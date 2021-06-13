#ifndef COMPANY_PROJECT_EMPLOYEE_H
#define COMPANY_PROJECT_EMPLOYEE_H

#include <ostream>
#include "istream"
#include "Person.h"

class Employee : public Person {
protected:
    int hourWork;
    int salaryPerHour;
    int workToDo;
    int workDone;
public:
    Employee(const string &, const string &, const Address &, int, int, int, int);

    Employee() = default;

    Employee(const Employee &);

    bool validate(string string1);

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

    Employee operator=(const Employee &);

    double calculateSalary() const;

    double efficiency() const;

};


#endif //COMPANY_PROJECT_EMPLOYEE_H
