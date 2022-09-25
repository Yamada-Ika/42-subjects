#include "PhoneBook.hpp"

#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook(void) : curIdx_(0) {}

void PhoneBook::Add(Contact &info) {
    if (curIdx_ >= 8) {
        curIdx_ = 0;
    }
    contacts_[curIdx_].setFirstName(info.getFirstName());
    contacts_[curIdx_].setLastName(info.getLastName());
    contacts_[curIdx_].setNickName(info.getNickName());
    contacts_[curIdx_].setPhoneNumber(info.getPhoneNumber());
    contacts_[curIdx_].setDarkestSecret(info.getDarkestSecret());
    curIdx_++;
}

static std::string truncStr(std::string s) {
    if (s.length() > 10)
        return s.substr(0, 9) + ".";
    return s;
}

static size_t StrToSizeT(std::string s) {
    std::stringstream ss(s);
    size_t n;
    ss >> n;
    return n;
}

static bool ContainChar(std::string s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return true;
    }
    return false;
}

void PhoneBook::Search(void) {
    std::cout << "     index|first name| last name|  nickname|" << std::endl;
    for (size_t i = 0; i < MAX_SIZE; i++) {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << truncStr(contacts_[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << truncStr(contacts_[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << truncStr(contacts_[i].getNickName()) << "|";
        std::cout << std::endl;
    }

    std::string input;
    while (true) {
        std::cout << "index : ";
        if (std::getline(std::cin, input)) {
            if (ContainChar(input)) {
                std::cerr << "error: invalid index" << std::endl;
                continue;
            }
            size_t i = StrToSizeT(input);
            if (i >= MAX_SIZE) {
                std::cerr << "error: invalid index" << std::endl;
                continue;
            }
            std::cout << "first name     : " << contacts_[i].getFirstName() << std::endl;
            std::cout << "last name      : " << contacts_[i].getLastName() << std::endl;
            std::cout << "nickname       : " << contacts_[i].getNickName() << std::endl;
            std::cout << "phone number   : " << contacts_[i].getPhoneNumber() << std::endl;
            std::cout << "darkest secret : " << contacts_[i].getDarkestSecret() << std::endl;
            break;
        }
        std::cerr << "error: failed to read" << std::endl;
        std::exit(1);
    }
}

void PhoneBook::Exit(void) {
    std::exit(0);
}
