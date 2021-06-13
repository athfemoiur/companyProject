#include <iostream>
#include "Employee.h"
#include "Company.h"

int main() {


    Boss b("ali", "93*x11111", Address(), 3, 6, 5, 1, 5);

    auto **pEmployee = new Employee *[5];

    pEmployee[0] = new Employee("amir", "89*a11121", Address(), 2, 5, 12, 12);
    pEmployee[1] = new Employee("amirhasd", "89*b11111", Address(), 5, 5, 20, 5);
    pEmployee[2] = new Employee("amircasdq", "89*c11111", Address(), 1, 5, 22, 12);
    pEmployee[3] = new Employee("amirxzv", "85*a11111", Address(), 20, 5, 20, 11);
    pEmployee[4] = new Employee("amirjgf", "90*a11111", Address(), 9, 5, 25, 17);
    Company c(1222, b, pEmployee);

//    c.writeOnFile();

    cout << c.getBoss().calculateSalary();

    c.changeBoss();



}
