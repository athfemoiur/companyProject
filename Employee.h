#ifndef COMPANY_PROJECT_EMPLOYEE_H
#define COMPANY_PROJECT_EMPLOYEE_H

#include <ostream>
#include "istream"
#include "Person.h"

class Employee : Person {
protected:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    explicit Employee(const string & = "", const string & = "90*11111", const Address & = Address(), int = 0, int = 0,
                      int = 0, int = 0);

    Employee(const Employee &);

    bool validate(string string1) override;

};


#endif //COMPANY_PROJECT_EMPLOYEE_H
