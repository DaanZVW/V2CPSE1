#ifndef SET_HPP
#define SET_HPP

#include "hwlib.hpp"
#include <iostream>

template< typename T, int N >
class set {
private:

    int pointer = 0;
    std::array<T, N> intset;

public:

    set(){}

    void add( T number ) {
        if (pointer < N) {
            for (int i = 0; i < pointer; i++) {
                if (intset[i] == number) {
                    return;
                }
            }
            intset[pointer] = number;
            pointer++;
        }
    }

    void remove( T number ) {
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

    bool contains( T number ) {
        for (int i = 0; i < pointer; ++i) {
            if (intset[i] == number) {
                return true;
            }
        }
        return false;
    }

    T max() {
        if (pointer > 0) {
            T tmp = intset[0];
            for (int i = 1; i < pointer; ++i) {
                if (tmp < intset[i]) {
                    tmp = intset[i];
                }
            }
            return tmp;
        }
        return T(0);
    }

    friend std::ostream & operator<<(std::ostream & co, const set & setob) {
        for (int i = 0; i < setob.pointer; ++i) {
            co << setob.intset[i] << " ";
        }
        return co;
    }
};

#endif