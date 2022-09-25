#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
 private:
    int hoge1;
    std::string hoge2;
    double hoge3;

 public:
    Data();
    ~Data();
    Data(const Data& other);
    Data& operator=(const Data& other);

    void setHoge1(int v);
    void setHoge2(const std::string& v);
    void setHoge3(double v);
    int getHoge1() const;
    const std::string& getHoge2() const;
    double getHoge3() const;
};

std::ostream& operator<<(std::ostream& lhs, const Data& rhs);

#endif
