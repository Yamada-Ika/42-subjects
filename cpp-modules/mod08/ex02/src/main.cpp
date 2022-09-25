#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <cassert>
#include <cstdlib>

#include "MutantStack.hpp"

#define DBG(a) std::cerr << a << std::endl

int main() {
  // pdf test
  {
    MutantStack<int> mstack;
    mstack.push(17);
    std::cout << "top  : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << "stack : " << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
  }

  {
    MutantStack<int> mstack;
    std::stack<int> st;

    assert(st.empty() == mstack.empty());
    for (int i = 0; i < 10; ++i) {
      int rnd = rand();
      st.push(rnd);
      mstack.push(rnd);
      // std::cout << "stack size  " << st.size() << std::endl;
      // std::cout << "mstack size " << mstack.size() << std::endl;
      assert(st.size() == mstack.size());
    }
    for (int i = 0; i < 10; ++i) {
      assert(st.top() == mstack.top());
      st.pop();
      mstack.pop();
    }
  }

  {
    MutantStack<std::string> mstack;
    std::stack<std::string> st;

    assert(st.empty() == mstack.empty());
    for (int i = 0; i < 10; ++i) {
      st.push("hello world");
      mstack.push("hello world");
      // std::cout << "stack size  " << st.size() << std::endl;
      // std::cout << "mstack size " << mstack.size() << std::endl;
      assert(st.size() == mstack.size());
    }
    for (int i = 0; i < 10; ++i) {
      assert(st.top() == mstack.top());
      st.pop();
      mstack.pop();
    }
  }


  {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    MutantStack<int>::iterator it = mstack.begin();
    assert(*it == 1);
    it++;
    assert(*it == 2);
    it++;
    assert(*it == 3);
    it++;
    assert(*it == 4);
    it++;
    assert(it == mstack.end());
  }

  {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    assert(*it == 4);
    it++;
    assert(*it == 3);
    it++;
    assert(*it == 2);
    it++;
    assert(*it == 1);
    it++;
    assert(it == mstack.rend());
  }

  {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    MutantStack<int> mstack2(mstack);
    mstack2.push(4);

    assert(mstack.top() == 3);
    mstack.pop();
    assert(mstack.top() == 2);
    mstack.pop();
    assert(mstack.top() == 1);
    mstack.pop();
    assert(mstack2.top() == 4);
    mstack2.pop();
    assert(mstack.empty() == mstack2.empty());
  }

  {
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    MutantStack<int> mstack2;
    mstack2 = mstack;
    mstack2.push(4);
    assert(mstack.top() == 3);
    mstack.pop();
    assert(mstack.top() == 2);
    mstack.pop();
    assert(mstack.top() == 1);
    mstack.pop();
    assert(mstack2.top() == 4);
    mstack2.pop();
    assert(mstack.empty() == mstack2.empty());
  }

  {
    std::list<int> lis;
    MutantStack<int> mstack;

    for (int i = 0; i < 10; ++i) {
      int rnd = rand();
      lis.push_back(rnd);
      mstack.push(rnd);
      // std::cout << "stack size  " << st.size() << std::endl;
      // std::cout << "mstack size " << mstack.size() << std::endl;
      assert(lis.size() == mstack.size());
    }
    for (int i = 0; i < 10; ++i) {
      assert(lis.back() == mstack.top());
      lis.pop_back();
      mstack.pop();
    }
  }
  return 0;
}
