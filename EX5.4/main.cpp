#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "set.hpp"

TEST_CASE( "MAX FUNCTION WITH CHARS" ){
    set<char, 10> s;
    s.add('D');
    s.add('c');
    s.add('y');
    s.add('P');
    REQUIRE( s.max() == 'y' ); 
}

TEST_CASE( "MAX FUNCTION WITH CHARS2" ){
    set<char, 10> s;
    s.add('R');
    s.add('C');
    s.add('A');
    s.add('Z');
    REQUIRE( s.max() == 'Z' ); 
}