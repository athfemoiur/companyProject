#include "Person.h"

Person::Person(const string &name, const string &id, const Address &address) {
    this->name = name;
    this->id = id;
    this->address = address;
    if (!validate(id)) { // if the id was invalid exit the program
        cout << "Invalid id";
        exit(1);
    }
}

Person::Person(const Person &p) {
    name = p.name;
    id = p.id;
    address = p.address;
}

bool Person::validate(string id) {
    // check the length
    int len = id.length();
    int temp = len - 7;
    if (len < 8 || len > 10)
        return false;
    // check the first two chars
    int firstTwo = stoi(id.substr(0, 2));
    if (firstTwo < 84 || firstTwo > 99)
        return false;
    // check the next 1 or 2 or 3 chars if they are number or not
    int i;
    for (i = 2; i < temp + 2; ++i) {
        if ((int) id[i] >= 48 && (int) id[i] <= 57)
            return false;
    }
    // check the last 5 chars to be between 4 and 6
    for (int j = i; j <= len; ++j) {
        if (id[j] >= '4' && id[j] <= '6')
            return false;
    }
    return true;
}

ostream &operator<<(ostream &out, const Person &p) {
    out << "name : " << p.name << " id : " << p.id << " address : " << p.address;

    return out;
}

istream &operator>>(istream &in, Person &p) {
    // take all of the inputs seperated by space
    in >> p.name >> p.id;
    cin >> p.address;
    return in;
}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}

const string &Person::getId() const {
    return id;
}

void Person::setId(const string &id) {
    Person::id = id;
}

const Address &Person::getAddress() const {
    return address;
}

void Person::setAddress(const Address &address) {
    Person::address = address;
}

Person &Person::operator=(const Person &p) {
    name = p.name;
    id = p.id;
    address = p.address;
    return *this;
}

