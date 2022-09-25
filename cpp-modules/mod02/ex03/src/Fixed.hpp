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

    Fixed operator+ (const Fixed& rhs) const;
    Fixed operator- (const Fixed& rhs) const;
    Fixed operator* (const Fixed& rhs) const;
    Fixed operator/ (const Fixed& rhs) const;
    bool operator< (const Fixed& rhs) const;
    bool operator<= (const Fixed& rhs) const;
    bool operator> (const Fixed& rhs) const;
    bool operator>= (const Fixed& rhs) const;
    bool operator== (const Fixed& rhs) const;
    bool operator!= (const Fixed& rhs) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static Fixed &max(Fixed& lhs, Fixed& rhs);
    static const Fixed &max(const Fixed& lhs, const Fixed& rhs);
    static Fixed &min(Fixed& lhs, Fixed& rhs);
    static const Fixed &min(const Fixed& lhs, const Fixed& rhs);
};

std::ostream& operator<<(std::ostream& lhs, const Fixed& rhs);

#endif
