#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
 private:
    int rawbits_;
    static const int fractbitswidth_ = 8;

 public:
    Fixed(void);
    explicit Fixed(int integer);
    explicit Fixed(float floater);
    Fixed(const Fixed& other);
    ~Fixed(void);
    Fixed& operator=(const Fixed& other);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt(void) const;
    float toFloat(void) const;
};

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs);

#endif
