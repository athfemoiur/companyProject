#ifndef COMPANY_PROJECT_BOSS_H
#define COMPANY_PROJECT_BOSS_H


#include <ostream>
#include "Employee.h"

class Boss : public Employee {
private:
    int numberOfEmployees;
public:
    explicit Boss(const string & = "", const string & = "90*11111", const Address & = Address(), int = 0, int = 0,
                  int = 0, int = 0, int= 0);

    Boss(const Boss &);

    int getNumberOfEmployees() const;

    void setNumberOfEmployees(int numberOfEmployees);

    friend ostream &operator<<(ostream &os, const Boss &boss);

    friend istream &operator>>(istream &in, Boss &boss);

    Boss &operator=(const Boss &);

    double calculateSalary() override;
};

#endif //COMPANY_PROJECT_BOSS_H
