#include <iostream>
#include <cstdlib>
#include <cassert>
#include <Array.tpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    for (int i = 0; i < MAX_VAL; i++)
    {
        assert(numbers[i] == mirror[i]);
    }

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    {
      const Array<int> hoge(10);
      // hoge[1] = 100;
    }

    {
      Array<int> hoge(0);
      int * h = new int[0];
      try {
        assert(hoge[0] == h[0]);
      } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
      }
      delete [] h;
    }

    return 0;
}
