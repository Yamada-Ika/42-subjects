#include <fstream>
#include <iostream>

#include "Harl.hpp"

enum msg_kind {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    NOSUCHLEVEL
};

#define MSG_N 4

int main(int argc, char *argv[]) {
    if (argc != 2
        || argv == NULL
        || argv[1] == NULL
    ) {
        std::cerr << "Error: Invalid argument" << std::endl;
        std::cerr << " Usage: ./harlFilter [msg]" << std::endl;
        std::cerr << "   msg:" << std::endl;
        std::cerr << "     DEBUG" << std::endl;
        std::cerr << "     INFO" << std::endl;
        std::cerr << "     WARNING" << std::endl;
        std::cerr << "     ERROR" << std::endl;
        return 1;
    }

    std::string msg = std::string(argv[1]);
    std::string msgs[MSG_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int msg_kind = NOSUCHLEVEL;

    for (int i = 0; i < MSG_N; i++) {
        if (msg == msgs[i]) {
            msg_kind = i;
            break;
        }
    }

    Harl harl;

    switch (msg_kind) {
    case DEBUG:
        std::cout << "[ DEBUG ]" << std::endl;
        harl.complain("DEBUG");
        std::cout << std::endl;
    case INFO:
        std::cout << "[ INFO ]" << std::endl;
        harl.complain("INFO");
        std::cout << std::endl;
    case WARNING:
        std::cout << "[ WARNING ]" << std::endl;
        harl.complain("WARNING");
        std::cout << std::endl;
    case ERROR:
        std::cout << "[ ERROR ]" << std::endl;
        harl.complain("ERROR");
        std::cout << std::endl;
        break;
    default:
        harl.complain("NOSUCHLEVEL");
        break;
    }

    return 0;
}
