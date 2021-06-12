#ifndef COMPANY_PROJECT_ADDRESS_H
#define COMPANY_PROJECT_ADDRESS_H

#include "iostream"
#include "istream"
#include "ostream"
using namespace std;

class Address {
private:
    string country;
    string city;
    string street;
public:
    explicit Address(string="" , string="" , string="" );

    friend ostream &operator<<(ostream &, const Address &);

    friend istream &operator>>(istream &, Address &);

};


#endif //COMPANY_PROJECT_ADDRESS_H
