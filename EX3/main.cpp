#include "hwlib.hpp"
#include "clock.hpp"
#include "locations.hpp"

int main( void ){
    //make a namespace target for less typing bcs wouter 
    namespace target = hwlib::target;
    
    //set the display pins
    auto scl = target::pin_oc( target::pins::scl );
    auto sda = target::pin_oc( target::pins::sda );
    auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
    auto display = hwlib::glcd_oled( i2c_bus, 0x3c );

    //set the hour and minute pins
    auto hour_input = target::pin_in( target::pins::d12 );
    auto minute_input = target::pin_in( target::pins::d13 );

    //positions clock
    constexpr hwlib::xy midpoint = hwlib::xy(63, 31);
    constexpr int radius = 28;

    //make location object
    constexpr locations l(midpoint, radius);

    //make clock object and set it up
    auto c = clock(display, midpoint, radius, hour_input, minute_input, l);
    c.setup();

    //constantly update the clock
    for(;;){
        c.update();
    }   
}