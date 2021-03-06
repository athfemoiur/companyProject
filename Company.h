#ifndef COMPANY_PROJECT_COMPANY_H
#define COMPANY_PROJECT_COMPANY_H

#include <ostream>
#include "Boss.h"

class Company {
private:
    int budget;
    Boss* boss;
    Employee ** employees;
public:
    Company(int, Boss *, Employee**);

    Company(const Company&);

    ~Company();

    int getBudget() const;

    void setBudget(int budget);

    Boss getBoss() const;

    void setBoss(Boss &boss);

    Employee **getEmployees() const;

    void setEmployees(Employee **employees);

    Employee* maxEfficiency() const;

    double averageEfficiency() const;

    void changeBoss();

    void gift();

    void payForService();

    bool isEnoughBudget();

    void writeOnFile();

    friend ostream &operator<<(ostream &os, const Company &company);

    friend istream &operator>>(istream &is, Company &company);



};


#endif //COMPANY_PROJECT_COMPANY_H
