#ifndef COMPANY_PROJECT_PERSON_H
#define COMPANY_PROJECT_PERSON_H
#include "Address.h"
#include "iostream"
#include "ostream"
#include "istream"
using namespace std;

class Person {
protected:
    string name;
    string id;
    Address address;
public:
    explicit Person(const string& = "", const string & = "90a11111", const Address& = Address());

    Person(const Person&);

    virtual bool validate(string);

    friend ostream &operator<<(ostream&, const Person&);

    friend istream &operator>>(istream&, Person&);

    const string &getName() const;

    void setName(const string &name);

    const string &getId() const;

    void setId(const string &id);

    const Address &getAddress() const;

    void setAddress(const Address &address);
};


#endif //COMPANY_PROJECT_PERSON_H
