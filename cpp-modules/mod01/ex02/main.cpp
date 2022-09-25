#include <string>
#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  // print address
  std::cout << &str << std::endl;
  std::cout << stringPTR << std::endl;
  std::cout << &stringREF << std::endl;

  // print value
  std::cout << str << std::endl;
  std::cout << *stringPTR << std::endl;
  std::cout << stringREF << std::endl;
}
