#include <string>
#include <iostream>
#include <sstream>
#include "Cast.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "error: Argument number should be two." << std::endl;
        std::cerr << "usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    Cast c(argv[1]);

    c.detectType();
    c.convert();
    c.print();

    return 0;
}
