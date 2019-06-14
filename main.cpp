// 
// piece of code counting the number of arguments of a function
// code by Twareintor: copyright (c) 2018 Claudiu Ciutacu
// works with C++ 11 too

#include <iostream>
#include <typeinfo>

/** C++ 17 only:
template<typename... Args>
auto sumUp(Args... args) { return (... + args); }
*/

/**  count the number of arguments of a function: works in C++ 11, 14
*/

// template<class A> // <-- doesn't works as template: compiles but hangs out
int cntArgs()
{
    return 0;
}

template<class A>
int cntArgs(A)
{
    return 1;
}

template<class A, class B>
int cntArgs(A, B)
{
    return 2;
}


template<class A, class... Args>
int cntArgs(A, Args... args)
{
    return 1 + cntArgs(args...);
}

template <class... Args>
int cntArgs(Args... args)
{
    return cntArgs(args...);
}

/**  EO: count the number of arguments of a function */

int main()
{
    std::cout << "Hello, world!\n";
    /* C++ 17: 
    auto x = sumUp(10, 12, 14, 11, 3);
    std::cout<<typeid(x).name()<<std::endl;
    */
    std::cout<<cntArgs(1, 2, "three", (float)4, 5, 6, 7)<<std::endl;
    std::cout<<cntArgs(1, 2, "3")<<std::endl;
    std::cout<<cntArgs(1)<<std::endl;
    std::cout<<cntArgs()<<std::endl; // <-- this doesn't work as template!!!
    std::cout << "Game Over\n";
}


