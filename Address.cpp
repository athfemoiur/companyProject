#include "Address.h"

using namespace std;

Address::Address(string country, string city, string street) :
        country(std::move(country)), city(std::move(city)), street(std::move(street)) {
}

ostream &operator<<(ostream &out, const Address &a) {
    out << a.country << " , " << a.city << " , " << a.street;
    return out;
}

istream &operator>>(istream &in, Address &a) {
    // take each string line by line or seperated by space
    string country;
    in >> country;
    string city;
    in >> city;
    string street;
    in >> street;
    a.country = country;
    a.city = city;
    a.street = street;
    return in;
}