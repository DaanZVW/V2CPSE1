#include "set.hpp"
#include <iostream>

int main( void ) {
    auto s = set();
    for (int i = 1; i < 15; i++) {
        s.add(i);
    }
    std::cout << s << std::endl;

    s.remove(4);
    s.remove(6);

    std::cout << s << std::endl;
    std::cout << s.contains(9) << std::endl;
    std::cout << s.contains(4) << std::endl;
    
}