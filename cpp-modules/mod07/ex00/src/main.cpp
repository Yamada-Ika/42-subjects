#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

#include "whatever.hpp"

#define DBG(a) std::cerr << a << std::endl

class Awesome {
 public:
  Awesome() : _n(0) {}
  Awesome(int n) : _n(n) {}
  // bool operator==(Awesome& rhs) const { return (this->_n == rhs._n); }
  // bool operator!=(Awesome& rhs) const { return (this->_n != rhs._n); }
  // bool operator>(Awesome& rhs) const { return (this->_n > rhs._n); }
  // bool operator<(Awesome& rhs) const { return (this->_n < rhs._n); }
  // bool operator>=(Awesome& rhs) const { return (this->_n >= rhs._n); }
  // bool operator<=(Awesome& rhs) const { return (this->_n <= rhs._n); }
  bool operator==(const Awesome& rhs) const { return (this->_n == rhs._n); }
  bool operator!=(const Awesome& rhs) const { return (this->_n != rhs._n); }
  bool operator>(const Awesome& rhs) const { return (this->_n > rhs._n); }
  bool operator<(const Awesome& rhs) const { return (this->_n < rhs._n); }
  bool operator>=(const Awesome& rhs) const { return (this->_n >= rhs._n); }
  bool operator<=(const Awesome& rhs) const { return (this->_n <= rhs._n); }
  int get_n() const { return _n; }

 private:
  int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main() {
  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

  const int e = 10;
  const int f = 14;

  assert(::min(e, f) == 10);
  assert(::max(e, f) == 14);
  assert(10 == ::min(e, f));
  assert(14 == ::max(e, f));

  Awesome g(121);
  Awesome h(120);

  ::swap(g, h);
  assert(Awesome(120) == g);
  assert(Awesome(121) == h);
  assert(Awesome(121) == ::max(g, h));
  assert(Awesome(120) == ::min(g, h));
  assert(g == Awesome(120));
  assert(h == Awesome(121));
  assert(::max(g, h) == Awesome(121));
  assert(::min(g, h) == Awesome(120));

  return 0;
}
