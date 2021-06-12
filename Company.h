#ifndef COMPANY_PROJECT_COMPANY_H
#define COMPANY_PROJECT_COMPANY_H

#include "Boss.h"

class Company {
private:
    int budget;
    Boss* boss;
    Employee ** employees;
public:
    explicit Company(int, const Boss&);

    Company(const Company&);

    ~Company();

    int getBudget() const;

    void setBudget(int budget);

    Boss getBoss() const;

    void setBoss(Boss boss);

    Employee **getEmployees() const;

    void setEmployees(Employee **employees);

    Employee* maxEfficiency();

    double averageEfficiency();

    void changeBoss();

    void gift();

    void payForService();

    bool isEnoughBudget();


};


#endif //COMPANY_PROJECT_COMPANY_H
