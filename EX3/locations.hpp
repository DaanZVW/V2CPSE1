#ifndef LOCATIONS_HPP
#define LOCATIONS_HPP

#include "hwlib.hpp"
#include <math.h>

#define MATH_PI 3.14159265359

class locations {
private:

    hwlib::xy midpoint;
    int radius;

    int minute_locations[60][2] = {};
    int hour_locations[60][2] = {};

public:

    constexpr locations(
        hwlib::xy midpoint,
        int radius
    ):
        midpoint (midpoint),
        radius (radius)
    {
        int i_minus = 0;
        float correction = 0.75;
        for (int i = 0; i < 60; i++) {
            if (i == 30) {
                i_minus = 30;
            }
            double x = sin(((i - i_minus) * 6) * MATH_PI / 180) * int(radius * correction);
            double y = sqrt(int(radius * correction)*int(radius * correction) - x*x);

            if ( i <= 15 ) {
                minute_locations[i][0] = midpoint.x + x;
                minute_locations[i][1] = midpoint.y - y;

            } else if ( i <= 30) {
                minute_locations[i][0] = midpoint.x + x;
                minute_locations[i][1] = midpoint.y + y; 

            } else if ( i <= 45) {
                minute_locations[i][0] = midpoint.x - x;
                minute_locations[i][1] = midpoint.y + y;

            } else {
                minute_locations[i][0] = midpoint.x - x;
                minute_locations[i][1] = midpoint.y - y;
            }
        }

        i_minus = 0;
        correction = 0.6;
        for (int i = 0; i < 60; i++) {
            if (i == 30) {
                i_minus = 30;
            }
            double x = sin(((i - i_minus) * 6) * MATH_PI / 180) * int(radius * correction);
            double y = sqrt(int(radius * correction)*int(radius * correction) - x*x);

            if ( i <= 15 ) {
                hour_locations[i][0] = midpoint.x + x;
                hour_locations[i][1] = midpoint.y - y;

            } else if ( i <= 30) {
                hour_locations[i][0] = midpoint.x + x;
                hour_locations[i][1] = midpoint.y + y; 

            } else if ( i <= 45) {
                hour_locations[i][0] = midpoint.x - x;
                hour_locations[i][1] = midpoint.y + y;

            } else {
                hour_locations[i][0] = midpoint.x - x;
                hour_locations[i][1] = midpoint.y - y;
            }
        }
    }
    
    int x(int index) const;
    int y(int index) const;
    int xh(int index) const;
    int yh(int index) const;
};

#endif