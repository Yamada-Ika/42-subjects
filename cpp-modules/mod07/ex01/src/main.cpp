#include <string>
#include <iostream>
#include <sstream>

#include "iter.hpp"

#define DBG(a) std::cerr << "dump : " << a << std::endl

class Awesome {
 public:
  Awesome() : _n(42) {}
  int get_n() const { return _n; }

 private:
  int _n;
};

std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

template < typename T >
void print(T const & x) { std::cout << x << std::endl; }

int main() {
  int tab[] = {0, 1, 2, 3, 4,};
  Awesome tab2[5];

  iter(tab, 5, print);
  iter(tab2, 5, print);

  return 0;
}
