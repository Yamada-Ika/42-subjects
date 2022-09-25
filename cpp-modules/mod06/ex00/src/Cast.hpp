#ifndef CAST_HPP
# define CAST_HPP

#include <iostream>
#include <string>

class Cast {
 private:
    std::string src;
    char char_n;
    int int_n;
    float float_n;
    double double_n;
    int impossible_flag;
    enum ImpossibleFlagsKind {
        kImpossibleInt = 1,
        kImpossibleChar,
        kImpossibleFloat,
        kImpossibleDouble
    };
    int datatype_flag;
    enum DataTypeKind {
        kInt = 1,
        kChar,
        kFloat,
        kDouble
    };

    template<class Target, class Source>
    Target narrow_cast(Source v);
    void setValFormSrc();
    void convertChar();
    void convertInt();
    void convertFloat();
    void convertDouble();
    void printInt();
    void printChar();
    void printFloat();
    void printDouble();
    Cast();

 public:
    Cast(const std::string& s);
    ~Cast();
    Cast(const Cast& other);
    Cast& operator=(const Cast& other);

    void detectType();
    void convert();
    void print();
};

# endif
