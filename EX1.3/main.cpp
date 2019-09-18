#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );
extern "C" void application();
extern "C" char convert_char( char s ) {
   if (s > 64 && s < 91) {
      return s + 32;
   } else if (s > 96 && s < 123) {
      return s - 32;
   }
   return s;
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}