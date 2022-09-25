#include "Cast.hpp"

#include <iostream>
#include <sstream>
#include <limits>

Cast::Cast(const std::string& s) : src(s),
        char_n(0),
        int_n(0),
        float_n(0.0f),
        double_n(0.0f),
        impossible_flag(0),
        datatype_flag(0) {}

Cast::~Cast() {}

Cast::Cast(const Cast& other) {
    *this = other;
}

Cast& Cast::operator=(const Cast& other) {
    if (this == &other) return *this;

    this->char_n = other.char_n;
    this->int_n = other.int_n;
    this->float_n = other.float_n;
    this->double_n = other.double_n;
    this->impossible_flag = other.impossible_flag;
    return *this;
}

static bool isDigit(const char c) {
    return '0' <= c && c <= '9';
}

static bool isSpecialKey(const std::string& s) {
    return (
        s == "-inff"
        || s == "+inff"
        || s == "nanf"
        || s == "-inf"
        || s == "+inf"
        || s == "nan"
    );
}

static bool isSpecialFloatKey(const std::string& s) {
    return (
        s == "-inff"
        || s == "+inff"
        || s == "nanf"
    );
}

void Cast::setValFormSrc() {
    std::istringstream iss(src);
    switch (datatype_flag) {
    case 1<<kInt:
        iss >> int_n;
        break;
    case 1<<kFloat:
        iss >> float_n;
        break;
    case 1<<kDouble:
        iss >> double_n;
        break;
    default:
        std::cerr << "Error: Unknown data type" << std::endl;
        std::exit(1);
    }
}

// detectType detect data type like 'float' and set value
void Cast::detectType() {
    // If src is equal to special keyword e.g. nan, inf
    if (isSpecialKey(src)) {
        if (isSpecialFloatKey(src)) {
            datatype_flag = 1<<kFloat;
            // Set float value
            if (src == "-inff") float_n = std::numeric_limits<float>::min();
            if (src == "+inff") float_n = std::numeric_limits<float>::max();
            if (src == "nanf") float_n = std::numeric_limits<float>::quiet_NaN();
        } else {
            datatype_flag = 1<<kDouble;
            // Set double value
            if (src == "-inf") double_n = std::numeric_limits<double>::min();
            if (src == "+inf") double_n = std::numeric_limits<double>::max();
            if (src == "nan") double_n = std::numeric_limits<double>::quiet_NaN();
        }
        return;
    }

    std::size_t s_len = src.length();

    // If length is equal to 1, value may be char type
    if (s_len == 1) {
        if (isDigit(src[0])) {
            datatype_flag = 1<<kInt;
            int_n = src[0] - '0';
        } else {
            datatype_flag = 1<<kChar;
            char_n = src[0];
        }
        return;
    }

    int dot_count = 0;
    for (std::size_t i = 0; i < s_len; ++i) {
        // Skip
        if (
            (src[i] == '.' && dot_count < 2) // '.' must exist only one
            && (i + 1 < s_len && isDigit(src[i + 1])) // number must exist next to '.'
        ) {
            ++dot_count;
            // If f terminated, data type may be float
            if (src[s_len - 1] == 'f') datatype_flag = 1<<kFloat;
            else datatype_flag = 1<<kDouble;
            continue;
        }
        if (isDigit(src[i])) continue;
        if (src[0] == '+' || src[0] == '-') continue;
        if (datatype_flag == (1<<kFloat) && (i + 1 == s_len && src[i] == 'f')) continue;

        return;
    }

    // If data type is unknown here, it may be int
    if (datatype_flag == 0) datatype_flag = 1<<kInt;

    // Set int, float and double value
    //   Eliminate 'f' because stringstream cannnot convert to float with it
    if (datatype_flag == (1<<kFloat)) src.erase(s_len-1, 1);
    
    setValFormSrc();
}

template<class Target, class Source>
Target Cast::narrow_cast(Source v) {
    Target r = static_cast<Target>(v);
    if (static_cast<Source>(r) != v) {
        throw std::runtime_error("narrow_cast<>() failed");
    }
    return r;
}

void Cast::convertInt() {
    try {
        char_n = narrow_cast<char>(int_n);
    } catch (std::exception &e) {
        impossible_flag |= (1<<kImpossibleChar);
    }
    float_n = static_cast<float>(int_n);
    double_n = static_cast<double>(int_n);
}

void Cast::convertChar() {
    int_n = static_cast<int>(char_n);
    float_n = static_cast<float>(char_n);
    double_n = static_cast<double>(char_n);
}

void Cast::convertFloat() {
    // nan is impossible for int and char
    if (float_n != float_n) impossible_flag = (1<<kImpossibleChar) | (1<<kImpossibleInt);

    try {
        char_n = narrow_cast<char>(float_n);
    } catch (std::exception& e) {
        impossible_flag |= (1<<kImpossibleChar);
    }
    try {
        int_n = narrow_cast<int>(float_n);
    } catch (std::exception& e) {
        impossible_flag |= (1<<kImpossibleInt);
    }
    double_n = static_cast<double>(float_n);
}

void Cast::convertDouble() {
    // nan is impossible for int and char
    if (double_n != double_n) impossible_flag = (1<<kImpossibleChar) | (1<<kImpossibleInt);

    try {
        char_n = narrow_cast<char>(double_n);
    } catch (std::exception& e) {
        impossible_flag |= (1<<kImpossibleChar);
    }
    try {
        int_n = narrow_cast<int>(double_n);
    } catch (std::exception& e) {
        impossible_flag |= (1<<kImpossibleInt);
    }
    try {
        float_n = narrow_cast<float>(double_n);
    } catch (std::exception& e) {
        impossible_flag |= (1<<kImpossibleFloat);
    }
}

void Cast::convert() {
    switch (datatype_flag) {
    case 1<<kInt:
        convertInt();
        break;
    case 1<<kChar:
        convertChar();
        break;
    case 1<<kFloat:
        convertFloat();
        break;
    case 1<<kDouble:
        convertDouble();
        break;
    default:
        std::cerr << "Error: Unknown data type" << std::endl;
        std::exit(1);
    }
}

static bool isPrint(const char c) {
    return ' ' <= c && c <= '~';
}

void Cast::printChar() {
    if (impossible_flag & (1<<kImpossibleChar)) {
        std::cout << "char: impossible" << std::endl;
    } else if (isPrint(char_n)) {
        std::cout << "char: " << char_n << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void Cast::printInt() {
    if (impossible_flag & (1<<kImpossibleInt)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << int_n << std::endl;
    }
}

void Cast::printFloat() {
    std::ostringstream oss;
    oss << float_n;

    if (impossible_flag & (1<<kImpossibleFloat)) {
        std::cout << "float: impossible" << std::endl;
    } else if (oss.str().find('.') == std::string::npos) {
        // integer value like '123' shoule display '123.0f'. See subject pdf
        std::cout << "float: " << float_n << ".0f" << std::endl;
    } else {
        std::cout << "float: " << float_n << "f" << std::endl;
    }
}

void Cast::printDouble() {
    std::ostringstream oss;
    oss << float_n;

    if (impossible_flag & (1<<kImpossibleDouble)) {
        std::cout << "double: impossible" << std::endl;
    } else if (oss.str().find('.') == std::string::npos) {
        // integer value like '123' shoule display '123.0'. See subject pdf
        std::cout << "double: " << double_n << ".0" << std::endl;
    } else {
        std::cout << "double: " << double_n << std::endl;
    }
}

void Cast::print() {
    printChar();
    printInt();
    printFloat();
    printDouble();
}
