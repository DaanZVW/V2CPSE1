#include "clock.hpp"
#include <math.h>

//make the circles around the clock
void clock::make_clock() {
    for (int i = 0; i < 60; i+=5) {
        hwlib::circle c(hwlib::xy(loc_array.x(i), loc_array.y(i)), int(radius / 9));
        c.draw( display );
    }
}

//move the pointers to it designated spot on the circle
void clock::move_pointers(bool add_min) {
    bool uphour = false;
    if (at_minute >= 60) {
        at_minute = 0;
    }
    if (minutes_past >= 12) {
        if (at_hour >= 59) {
            at_hour = 0;
        } else {
            uphour = true;
        }
        minutes_past = 0;
    }

    hwlib::line pm(midpoint, hwlib::xy(loc_array.x(at_minute), loc_array.y(at_minute)));
    hwlib::line ph(midpoint, hwlib::xy(loc_array.xh(at_hour), loc_array.yh(at_hour)));
    pm.draw( display );
    ph.draw( display );

    if (uphour){
        at_hour++;
    }
    if (add_min) {
        at_minute++;
        minutes_past++;
    }
}

//give true back if a minute has passed
bool clock::check_time() {
    if (sec_now < int(hwlib::now_us() / 1000000)) {
        sec_now = int(hwlib::now_us() / 1000000);
        seconds_past++;
    }
    if (seconds_past >= 60) {
        seconds_past = 0;
        return true;
    }
    return false;
}

void clock::update() {
    //refresh the buttons
    minute_input.refresh();
    hour_input.refresh();

    //add an hour if hour button is pressed
    if (hour_input.read()) {
        if (at_hour >= 55) {
            at_hour -= 60;
        }
        at_hour += 5;
      
    }

    //check if minute has passed or if the minute button or hour button is pressed
    if(check_time() || minute_input.read() || hour_input.read()) {

        //clear the screen buffer
        display.clear();

        //make the circles around the clock
        make_clock();

        //make the pointers
        move_pointers(!hour_input.read());

        //write the screen buffer to the screen
        display.flush();
    }    
}

void clock::setup() {
    //make the clock
    display.clear();
    make_clock();
    move_pointers(true);
    display.flush();
}




