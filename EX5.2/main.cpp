#include "set.hpp"
#include <iostream>

int main( void ) {
    set<double, 10> s;
    s.add(3.512);
    s.add(36.312);
    s.add(23.31);
    s.add(1.5235);

    std::cout << s << std::endl;
    
    s.remove(36.312);
    s.remove(321.53);

    std::cout << s << std::endl;
    std::cout << s.contains(23.31) << std::endl;
    std::cout << s.contains(12.3) << std::endl;


    set<int, 25> s2;
    for (int i = 0; i < 30; ++i) {
        s2.add(i*4);
    }

    std::cout << s2 << std::endl;
    
    s2.remove(16);
    s2.remove(19);

    std::cout << s2 << std::endl;
    std::cout << s2.contains(28) << std::endl;
    std::cout << s2.contains(30) << std::endl;
}