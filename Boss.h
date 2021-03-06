#ifndef COMPANY_PROJECT_BOSS_H
#define COMPANY_PROJECT_BOSS_H

#include <ostream>
#include "Employee.h"

class Boss : public Employee {
private:
    int numberOfEmployees;
public:
    Boss(const string &, const string &, const Address &, int, int,
         int, int, int);

    Boss(const Boss &);

    int getNumberOfEmployees() const;

    void setNumberOfEmployees(int numberOfEmployees);

    friend ostream &operator<<(ostream &os, const Boss &boss);

    friend istream &operator>>(istream &in, Boss &boss);

    Boss &operator=(const Boss &);

    double calculateSalary() const;
};

#endif //COMPANY_PROJECT_BOSS_H
