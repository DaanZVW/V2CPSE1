#ifndef GENERATE_SONG_HPP
#define GENERATE_SONG_HPP

#include <fstream>
#include <iostream>
#include "rtttl_player.hpp"

class generate : public note_player {
private:

    std::string filename;

public:

    generate(std::string filename):
        filename( filename ) {}

    void play(const note & n);
    void make_begin();
    void make_end();
    
};

#endif