#include "Contact.hpp"

Contact::Contact(void) : first_name_(""), last_name_(""),
    nickname_(""), phone_number_(""), darkest_secret_("") {}

void Contact::setFirstName(std::string first_name) {
    first_name_ = first_name;
}

void Contact::setLastName(std::string last_name) {
    last_name_ = last_name;
}

void Contact::setNickName(std::string nickname) {
    nickname_ = nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
    phone_number_ = phone_number;
}

void Contact::setDarkestSecret(std::string darkest_secret) {
    darkest_secret_ = darkest_secret;
}

std::string Contact::getFirstName(void) {
    return first_name_;
}

std::string Contact::getLastName(void) {
    return last_name_;
}

std::string Contact::getNickName(void) {
    return nickname_;
}

std::string Contact::getPhoneNumber(void) {
    return phone_number_;
}

std::string Contact::getDarkestSecret(void) {
    return darkest_secret_;
}
