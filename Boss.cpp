#include "Boss.h"

Boss::Boss(const string &name, const string &id, const Address &address, int h, int ph, int wtd, int wd, int n)
        : Employee(name, id, address, h, ph, wtd, wd) , numberOfEmployees(n) {
}

Boss::Boss(const Boss &b) : Employee(b) {
    numberOfEmployees = b.numberOfEmployees;
}

int Boss::getNumberOfEmployees() const {
    return numberOfEmployees;
}

void Boss::setNumberOfEmployees(int numberOfEmployees) {
    Boss::numberOfEmployees = numberOfEmployees;
}

ostream &operator<<(ostream &os, const Boss &boss) {
    os << static_cast<const Employee &>(boss) << " numberOfEmployees: " << boss.numberOfEmployees;
    return os;
}

istream &operator>>(istream &in, Boss &boss) {
    in >> static_cast<Employee &>(boss) >> boss.numberOfEmployees;
    return in;
}

Boss &Boss::operator=(const Boss &b) {
    Employee::operator=(b);
    numberOfEmployees = b.numberOfEmployees;
    return *this;
}

double Boss::calculateSalary() const { // same as the Employee class, only we need * 1.15 because it's boss
    return Employee::calculateSalary() * 1.15;
}