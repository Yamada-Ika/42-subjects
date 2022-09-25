#include <fstream>
#include <iostream>

#include "Sed.hpp"

enum state {
    SUCCESS,
    FAIL
};

int validate(int argc, char *argv[]) {
    if (argc != 4
        || argv == NULL
        ) {
        return FAIL;
    }
    for (int i = 0; i < argc; i++) {
        if (argv[i] == NULL) {
            return FAIL;
        }
    }
    return SUCCESS;
}

int main(int argc, char *argv[]) {
    if (validate(argc, argv) == FAIL) {
        std::cerr << "Error: Invalid argument" << std::endl;
        std::cerr << "  Usage: ./sed [filepath] [s1] [s2]" << std::endl;
        return 1;
    }
    Sed sed(argv[1], argv[2], argv[3]);
    sed.replace();
    return 0;
}
