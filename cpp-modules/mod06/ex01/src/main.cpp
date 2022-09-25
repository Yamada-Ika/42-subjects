#include <string>
#include <iostream>
#include <sstream>
#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    Data d;

    std::cout << d << std::endl;

    uintptr_t r = serialize(&d);
    Data *dd = deserialize(r);

    std::cout << *dd << std::endl;

    return 0;
}
