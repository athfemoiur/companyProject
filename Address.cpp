#include "Address.h"

#include <utility>

using namespace std;

Address::Address(string country, string city, string street) :
        country(std::move(country)), city(std::move(city)), street(std::move(street)) {
}
