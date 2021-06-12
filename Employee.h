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

    friend ostream &operator<<(ostream &os, const Employee &employee);

    friend istream &operator>>(istream &os, Employee &employee);

    int getHourWork() const;

    void setHourWork(int hourWork);

    int getSalaryPerHour() const;

    void setSalaryPerHour(int salaryPerHour);

    int getWorkToDo() const;

    void setWorkToDo(int workToDo);

    int getWorkDone() const;

    void setWorkDone(int workDone);

    Employee& operator=(const Employee &);

};


#endif //COMPANY_PROJECT_EMPLOYEE_H
