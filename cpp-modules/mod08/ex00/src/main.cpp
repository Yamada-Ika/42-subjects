#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

#include "easyfind.hpp"

#define DBG(a) std::cerr << a << std::endl

int main() {
  {
    std::vector<int> v;

    v.push_back(3);
    v.push_back(1);
    v.push_back(4);
    std::vector<int>::const_iterator itr = easyfind(v, 3);
    std::cout << "try to find 3 in {3, 1, 4}" << std::endl;
    if (itr == v.end()) {
      std::cout << "Not found..." << std::endl;
    } else {
      std::cout << "found : " << *itr << std::endl;
    }
    ++itr;
    assert(*itr == 1);

    itr = easyfind(v, 100);
    std::cout << "try to find 100 in {3, 1, 4}" << std::endl;
    if (itr == v.end()) {
      std::cout << "Not found..." << std::endl;
    } else {
      std::cout << "found : " << *itr << std::endl;
    }
  }

  {
    std::vector<int> v;

    v.push_back(3);
    std::vector<int>::iterator itr = easyfind(v, 3);
    *itr = 100;
    assert(*itr == 100);
  }

  return 0;
}
