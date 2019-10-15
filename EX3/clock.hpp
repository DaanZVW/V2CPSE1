#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "hwlib.hpp"
#include "locations.hpp"

class clock {
private:

    //input variables
    hwlib::window & display;
    hwlib::xy midpoint;
    int radius;
    hwlib::pin_in & hour_input;
    hwlib::pin_in & minute_input;
    const locations &loc_array;

    //pointer variables
    //NOTE: hour also goes to 60 for smooth hour change
    int at_minute = 0;
    int at_hour = 0;
    int minutes_past = 0;

    //clock variables
    int seconds_past = 0;
    int sec_now = 0;

    //private functions
    void make_clock();
    void move_pointers(bool add_min);
    bool check_time();

public:
    clock(
        hwlib::window & display,
        hwlib::xy midpoint,
        int radius,
        hwlib::pin_in & hour_input,
        hwlib::pin_in & minute_input,
        const locations &loc_array
    ):
        display ( display ),
        midpoint ( midpoint ),
        radius ( radius ),
        hour_input ( hour_input ),
        minute_input ( minute_input ),
        loc_array ( loc_array )
    {}

    //master function, calls other functions
    void update();
    void setup();
};

#endif