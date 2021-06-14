#include "Company.h"
#include "fstream"
#include "iostream"

Company::Company(int budget, Boss* b, Employee **emp) : budget(budget) {
    // allocate memory for boss and all of the employees
    boss = new Boss(*b);
    employees = new Employee *[boss->getNumberOfEmployees()];
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        employees[i] = new Employee(*emp[i]);
    }
//    gift(); // call these two methods here to avoid calling them multiple times
//    payForService();
}

Company::Company(const Company &c) {
    this->budget = c.budget;
    this->boss = new Boss(*c.boss);
    this->employees = new Employee *[c.boss->getNumberOfEmployees()];
    for (int i = 0; i < c.boss->getNumberOfEmployees(); ++i) {
        employees[i] = new Employee(*c.employees[i]);
    }
}

Company::~Company() {
    // delete memory of all of the employees and boss
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        delete employees[i];
    }
    delete[] employees;
    delete boss;
}

int Company::getBudget() const {
    return budget;
}

void Company::setBudget(int budget) {
    Company::budget = budget;
}

Boss Company::getBoss() const {
    return *boss;
}

void Company::setBoss(Boss &boss) {
    *this->boss = boss;
}

Employee **Company::getEmployees() const {
    return employees;
}

void Company::setEmployees(Employee **employees) {
    Company::employees = employees;
}

Employee *Company::maxEfficiency() const {
    // return a pointer to the employee with maximum efficiency
    Employee *max = employees[0];
    for (int i = 1; i < boss->getNumberOfEmployees(); ++i) {
        if (employees[i]->efficiency() > max->efficiency())
            max = employees[i];
    }
    return max;
}

double Company::averageEfficiency() const {
    double sum = 0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        sum += employees[i]->efficiency();
    }
    return sum;
}

void Company::changeBoss() {

    if (boss->efficiency() < 40.0) {
        Employee *max = maxEfficiency(); // get the max efficiency
        for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
            if (employees[i]->efficiency() == max->efficiency()) {
                int numberOfEmployee = boss->getNumberOfEmployees();
                Employee *temp = boss; // store the value of boss
                boss = static_cast<Boss *>(employees[i]); // assign the max efficiency employee to boss with casting
                employees[i] = temp; // assign the boss which we stored earlier to that employee
                boss->setNumberOfEmployees(numberOfEmployee); // set the number of employees for the new boss
                break;
            }
        }
    }
}

void Company::gift() const {
    Employee *max = maxEfficiency();
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (stoi(employees[i]->getId().substr(0, 2)) < 90) // check if the first two chars of id is < 90
            employees[i]->setHourWork(employees[i]->getHourWork() + 5);
        if (employees[i] == max) // check if the employee has max efficiency
            employees[i]->setHourWork(employees[i]->getHourWork() + 10);
    }
    if (stoi(boss->getId().substr(0, 2)) < 90) // check if the first two chars of id is < 90
        boss->setHourWork(boss->getHourWork() + 5);
}

void Company::payForService() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (employees[i]->getAddress().getCity() != "Tehran")
            employees[i]->setHourWork(employees[i]->getHourWork() + 7);
    }
    if (boss->getAddress().getCity() != "Tehran")
        boss->setHourWork(boss->getHourWork() + 7);
}

bool Company::isEnoughBudget() {
    double payment = 0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        payment += employees[i]->calculateSalary();
    }
    payment += boss->calculateSalary();
    if (payment <= budget)
        return true;
    return false;
}

void Company::writeOnFile() const {
    fstream f("data.txt", ios::out);
    f << boss->getName() << " " << boss->getId() << " " << boss->efficiency() << " " <<
      boss->calculateSalary() << endl;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        f << employees[i]->getName() << " " << employees[i]->getId() << " " << employees[i]->efficiency() << " " <<
          employees[i]->calculateSalary() << endl;
    }
}

ostream &operator<<(ostream &os, const Company &company) {
    // copy the value of employees to another array to avoid changes in the original array
    int n = company.boss->getNumberOfEmployees();
    Employee newEmployees[n];
    for (int i = 0; i < n; ++i) {
        newEmployees[i] = *company.employees[i];
    }
    for (int i = 0; i < n - 1; ++i) { // use bubble sort to sort based on the id's first two chars
        for (int j = n - 1; j > i; --j) {
            if (newEmployees[j].getId().substr(0, 2) < newEmployees[j - 1].getId().substr(0, 2))
                swap(newEmployees[j], newEmployees[j - 1]);
        }
    }
    for (int i = 0; i < n - 1; ++i) { // use bubble sort to sort based on the name
        for (int j = n - 1; j > i; --j) {
            if (newEmployees[j].getId().substr(0, 2) == newEmployees[j - 1].getId().substr(0, 2) &&
                newEmployees[j].getName() < newEmployees[j - 1].getName())
                swap(newEmployees[j], newEmployees[j - 1]);
        }
    }
    os << *company.boss << endl;
    for (int i = 0; i < n; ++i) {
        os << newEmployees[i] << endl;
    }
    return os;
}

istream &operator>>(istream &in, Company &company) {
    in >> company.budget;
    in >> (*company.boss);
    for (int i = 0; i < company.boss->getNumberOfEmployees(); ++i) {
        in >> (*company.employees[i]);
    }
    return in;
}
