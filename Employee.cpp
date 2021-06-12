#include "Employee.h"

Employee::Employee(const string &name, const string &id, const Address &address, int h, int ph, int wtd, int wd) :
        Person(name, id, address) {
    if (!validate(id)) {
        cout << "Invalid input";
        exit(1);
    }
    this->hourWork = h;
    this->salaryPerHour = ph;
    this->workToDo = wtd;
    this->workDone = wd;
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
