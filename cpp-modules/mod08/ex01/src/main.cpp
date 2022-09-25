#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <time.h>
#include <cassert>

#include "Span.hpp"

int main() {
  // normal test
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortest : " << sp.shortestSpan() << std::endl;
    std::cout << "longest  : " << sp.longestSpan() << std::endl;
  }

  // exception
  {
    try {
      Span sp = Span(100);
      sp.shortestSpan();
    }
    catch(const std::exception& e) {
      std::cerr << "exeption test 1 " << e.what() << ". If you see this, It's ok" << '\n';
    }
    try {
      Span sp = Span(100);
      sp.addNumber(1);
      sp.longestSpan();
    }
    catch(const std::exception& e) {
      std::cerr << "exeption test 2 " << e.what() << ". If you see this, It's ok" << '\n';
    }
    try {
      Span sp = Span(100);
      sp.addNumber(1);
      sp.addNumber(1);
      sp.longestSpan();
    }
    catch(const std::exception& e) {
      std::cerr << "exeption test 3 " << e.what() << ". If you see this, It's wrong!" << '\n';
    }
    try {
      Span sp = Span(0);
      sp.addNumber(1);
    }
    catch(const std::exception& e) {
      std::cerr << "exeption test 4 " << e.what() << ". If you see this, It's ok" << '\n';
    }
    try {
      Span sp = Span(1);
      sp.addNumber(1);
      sp.addNumber(1);
    }
    catch(const std::exception& e) {
      std::cerr << "exeption test 5 " << e.what() << ". If you see this, It's ok" << '\n';
    }
  }

  // test 100000 numbers
  {
    std::vector<int> vec;
    for (int i = 0; i < 100000; ++i) {
      vec.push_back(i);
    }
    Span sp(100000);
    sp.addNumbers(vec.begin(), vec.end());
    assert(sp.shortestSpan() == 1);
    assert(sp.longestSpan() == (100000 - 1));
  }

  // minus value
  {
    Span sp(10);
    sp.addNumber(-1000);
    sp.addNumber(-1001);
    sp.addNumber(-10000000);
    sp.addNumber(-10001000);
    assert(sp.shortestSpan() == 1);
    assert(sp.longestSpan() == 10000000);
  }

  return 0;
}
