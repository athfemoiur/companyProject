#include "Employee.h"

Employee::Employee(const string &name, const string &id, const Address &address, int h, int ph, int wtd, int wd) :
        Person(name, id, address) {
    this->hourWork = h;
    this->salaryPerHour = ph;
    this->workToDo = wtd;
    this->workDone = wd;
    if (!validate(id)) { // if the id was invalid exit the program
        cout << "Invalid input";
        exit(1);
    }

}


bool Employee::validate(string id) {
    if (id[2] != '*')
        return false;
    return Person::validate(id);
}

Employee::Employee(const Employee &e) : Person(e) {
    hourWork = e.hourWork;
    salaryPerHour = e.salaryPerHour;
    workToDo = e.workToDo;
    workDone = e.workDone;
}

ostream &operator<<(ostream &os, const Employee &employee) {
    os << static_cast<const Person &>(employee) << endl << "hour work : " << employee.hourWork << " salary per hour : "
       << employee.salaryPerHour << " work to do :  " << employee.workToDo << " work done : " << employee.workDone;
    return os;
}

istream &operator>>(istream &in, Employee &employee) {
    in >> static_cast<Person &>(employee) >> employee.hourWork >> employee.salaryPerHour >> employee.workToDo
       >> employee.workDone;
    return in;
}

int Employee::getHourWork() const {
    return hourWork;
}

void Employee::setHourWork(int hourWork) {
    Employee::hourWork = hourWork;
}

int Employee::getSalaryPerHour() const {
    return salaryPerHour;
}

void Employee::setSalaryPerHour(int salaryPerHour) {
    Employee::salaryPerHour = salaryPerHour;
}

int Employee::getWorkToDo() const {
    return workToDo;
}

void Employee::setWorkToDo(int workToDo) {
    Employee::workToDo = workToDo;
}

int Employee::getWorkDone() const {
    return workDone;
}

void Employee::setWorkDone(int workDone) {
    Employee::workDone = workDone;
}

Employee& Employee::operator=(const Employee &e) {
    Person::operator=(e);
    hourWork = e.hourWork;
    salaryPerHour = e.salaryPerHour;
    workToDo = e.workToDo;
    workDone = e.workDone;
    return *this;
}

double Employee::calculateSalary() const { // salary is salary per hour * hour work then we decrease based on the work
    double decrease = (double) workDone / workToDo;
    return salaryPerHour * hourWork * decrease;
}

double Employee::efficiency() const {
    double temp = (double) workDone / workToDo;
    return temp / hourWork * 100;
}