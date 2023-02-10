#include <iostream>
#include <type_traits>
#include "ft_type_traits.hpp"

int  foo(int t)
{
    std::cout << "foo called with an int value: " << t << std::endl;
    return t;
}


template<typename T>
typename ft::enable_if<std::is_pointer<T>::value, T>::type
foo(T t)
{
    std::cout << "foo called with an integral value: " << *t << std::endl;
    return t;
}


int main()
{
    int i = 5;
    int *b = &i;
    foo(5);
    foo(b);
    foo(5.6);  // This will call the foo function    // double d = foo(3.14); // This will not call the foo function, 
                        //because 3.14 is not an integral value and the function is disabled
    return 0;
}