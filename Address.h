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
    Address(string , string , string );

    Address() = default;

    friend ostream &operator<<(ostream &, const Address &);

    friend istream &operator>>(istream &, Address &);

    const string &getCountry() const;

    void setCountry(const string &country);

    const string &getCity() const;

    void setCity(const string &city);

    const string &getStreet() const;

    void setStreet(const string &street);
};


#endif //COMPANY_PROJECT_ADDRESS_H
