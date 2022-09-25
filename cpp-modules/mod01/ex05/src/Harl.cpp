#include "Harl.hpp"

#include <iostream>

void Harl::debug(void) {
    std::cout << "I love having extra bacon for ";
    std::cout << "my 7XL-double-cheese-triple-pickle-specialketchup burger.";
    std::cout << " I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "I cannot believe adding extra bacon costs more money.";
    std::cout << " You didn't put enough bacon in my burger!";
    std::cout << " If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "I think I deserve to have some extra bacon for free.";
    std::cout << " I've been coming for years whereas you started";
    std::cout << " working here since last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    HarlMemFunc funcs[FUNC_N] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[FUNC_N] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < FUNC_N; i++) {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "Probably complaining about insignificant problems" << std::endl;
}
