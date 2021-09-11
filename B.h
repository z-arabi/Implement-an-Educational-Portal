// #include "A.h"
#include <iostream>
class A;

class B
{
    public:
    B(int n)
    {
        A* a{};
        std::cout << a->id << "**\n";
    }
   /* the compiler now knows the size of "A", so we can have a field
      of type "A". */
   

};