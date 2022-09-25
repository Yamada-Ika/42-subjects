#include <string>
#include <iostream>
#include <cstdlib>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void) {
    PhoneBook phone_book;
    Contact contact;
    std::string input;

    while (true) {
        std::cout << "command : ";
        if (std::getline(std::cin, input)) {
            if (input == "ADD") {
                std::cout << "first name : ";
                if (!std::getline(std::cin, input)) {
                    std::cerr << "error: failed to read" << std::endl;
                    std::exit(1);
                }
                contact.setFirstName(input);
                std::cout << "last name : ";
                if (!std::getline(std::cin, input)) {
                    std::cerr << "error: failed to read" << std::endl;
                    std::exit(1);
                }
                contact.setLastName(input);
                std::cout << "nickname : ";
                if (!std::getline(std::cin, input)) {
                    std::cerr << "error: failed to read" << std::endl;
                    std::exit(1);
                }
                contact.setNickName(input);
                std::cout << "phone number : ";
                if (!std::getline(std::cin, input)) {
                    std::cerr << "error: failed to read" << std::endl;
                    std::exit(1);
                }
                contact.setPhoneNumber(input);
                std::cout << "darkest secret : ";
                if (!std::getline(std::cin, input)) {
                    std::cerr << "error: failed to read" << std::endl;
                    std::exit(1);
                }
                contact.setDarkestSecret(input);
                phone_book.Add(contact);
                continue;
            }
            if (input == "SEARCH") {
                phone_book.Search();
                continue;
            }
            if (input == "EXIT") {
                phone_book.Exit();
            }
            std::cerr << "error: Invalid command" << std::endl;
            continue;
        }
        std::cerr << "error: failed to read" << std::endl;
        std::exit(1);
    }
    return 0;
}
