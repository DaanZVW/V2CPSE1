#include "set.hpp"
#include <iostream>

int main( void ) {
    set<char, 10> s;
    s.add('D');
    s.add('c');
    s.add('y');
    s.add('P');

    std::cout << s.max() << std::endl;
}