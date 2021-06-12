#include "Company.h"


Company::Company(int budget, const Boss &boss) {
    this->budget = budget;
    this->boss = new Boss(boss);
    this->employees = new Employee *[boss.getNumberOfEmployees()];
    for (int i = 0; i < boss.getNumberOfEmployees(); ++i) {
        employees[i] = new Employee;
    }
}

Company::Company(const Company &c) {
    budget = c.budget;
    boss = c.boss;
    employees = c.employees;
}

Company::~Company() {
    delete boss;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        delete[] employees[i];
    }
    delete[] employees;
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

void Company::setBoss(Boss boss) {
    *this->boss = boss;
}

Employee **Company::getEmployees() const {
    return employees;
}

void Company::setEmployees(Employee **employees) {
    Company::employees = employees;
}

Employee *Company::maxEfficiency() {
    Employee *max = *employees;
    for (int i = 1; i < boss->getNumberOfEmployees(); ++i) {
        if (employees[i]->efficiency() > max->efficiency())
            max = employees[i];
    }
    return max;
}

double Company::averageEfficiency() {
    double sum = 0;
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        sum += employees[i]->efficiency();
    }
    return sum;
}

void Company::changeBoss() {
    if (boss->efficiency() < 40)
        for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
            if (employees[i] == maxEfficiency()) {
                Boss *temp = boss;
                int n = boss->getNumberOfEmployees();
                boss = dynamic_cast<Boss *> (employees[i]);
                boss->setNumberOfEmployees(n);
                employees[i] = dynamic_cast<Employee *> (temp);
            }
        }
}

void Company::gift() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (stoi(employees[i]->getId().substr(0, 2)) < 90)
            employees[i]->setHourWork(employees[i]->getHourWork() + 5);
        if (employees[i] == maxEfficiency())
            employees[i]->setHourWork(employees[i]->getHourWork() + 10);
    }
}

void Company::payForService() {
    for (int i = 0; i < boss->getNumberOfEmployees(); ++i) {
        if (employees[i]->getAddress().getCity() != "Tehran")
            employees[i]->setHourWork(employees[i]->getHourWork() + 7);
    }
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
