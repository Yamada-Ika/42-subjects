#include <string>
#include <cstring>
#include <iostream>

std::string toUpperStr(std::string s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            s[i] = std::toupper(s[i]);
    }
    return s;
}

std::string eraseSpaces(std::string s) {
    size_t s_len = s.length();
    if (s_len == 0) {
        return s;
    }

    size_t lhs_idx = 0;
    size_t rhs_idx = s_len - 1;
    for (size_t i = 0; i < s_len; i++) {
        if (s[i] == ' ') {
            continue;
        }
        lhs_idx = i;
        break;
    }
    for (size_t i = s_len - 1; i >= lhs_idx; i--) {
        if (s[i] == ' ') {
            continue;
        }
        rhs_idx = i;
        break;
    }
    return s.substr(lhs_idx, rhs_idx - lhs_idx + 1);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    std::string res = "";
    for (size_t i = 1; argv[i] != NULL; i++) {
        res += toUpperStr(eraseSpaces(std::string(argv[i])));
        if (argv[i + 1] != NULL) {
            res += " ";
        }
    }
    std::cout << res << std::endl;
    return 0;
}
