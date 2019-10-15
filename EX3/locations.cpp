#include "locations.hpp"

 int locations::x(int index) const {
    return minute_locations[index][0];
}

 int locations::y(int index) const {
    return minute_locations[index][1];
}

 int locations::xh(int index) const {
    return hour_locations[index][0];
}

 int locations::yh(int index) const {
    return hour_locations[index][1];
}