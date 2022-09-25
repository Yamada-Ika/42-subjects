#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    srand(time(NULL));

    int r = rand();

    switch (r % 3) {
    case 0:
        std::cout << "create : A" << std::endl;
        return new A();
    case 1:
        std::cout << "create : B" << std::endl;
        return new B();
    default:
        std::cout << "create : C" << std::endl;
        return new C();
    }
}
void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } else {
        std::cerr << "Error: Unknown type" << std::endl;
        std::exit(1);
    }
}

void identify(Base& p) {
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}
    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}
}

int main() {
    Base *b = generate();

    identify(b);
    identify(*b);

    delete b;
    return 0;
}
