#include "set.hpp"
#include <iostream>

int main( void ) {
    set<double, 10> s;
    s.add(3.512);
    s.add(36.312);
    s.add(23.31);
    s.add(1.5235);
    s.add(329.3213);
    std::cout << s << std::endl;
    
    s.remove(36.312);
    s.remove(321.53);

    std::cout << s << std::endl;
    std::cout << s.contains(23.31) << std::endl;
    std::cout << s.contains(12.3) << std::endl;
    std::cout << s.max() << std::endl;
}