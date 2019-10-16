#ifndef SET_HPP
#define SET_HPP

#include "hwlib.hpp"
#include <iostream>

class set {
private:

    int pointer = 0;
    int maxInts = 10;
    int intset[10] = {};

public:

    set(){}

    void add( int number ) {
        if (pointer < maxInts) {
            intset[pointer] = number;
            pointer++;
        }
    }

    void remove( int number ) {
        for (int i = 0; i < pointer; ++i) {
            if (intset[i] == number) {
                for (int j = i; j < pointer; j++) {
                    intset[j] = intset[j+1];
                }
                pointer--;
                break;
            }
        }
    }

    bool contains( int number ) {
        for (int i = 0; i < pointer; ++i) {
            if (intset[i] == number) {
                return true;
            }
        }
        return false;
    }

    friend std::ostream & operator<<(std::ostream & co, const set & setob) {
        for (int i = 0; i < setob.pointer; ++i) {
            co << setob.intset[i] << " ";
        }
        return co;
    }
};

#endif