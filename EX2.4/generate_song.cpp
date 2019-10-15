#include "generate_song.hpp"
#include <fstream>
#include <iostream>

void generate::play(const note & n) {
    std::ofstream song;
    song.open(filename, std::ofstream::app);
    song << "\n\t\tp.play( note{ " << n.frequency << ",\t" << n.duration << " } );";
    song.close();
}

void generate::make_begin() {
    std::ofstream song;
    song.open(filename);
    song << "#ifndef SONG_HPP\n#define SONG_HPP\n\n#include \"melody.hpp\"\n\nclass song : public melody {\npublic:\n\tvoid play( note_player & p ){";
    song.close();
}

void generate::make_end() {
    std::ofstream song;
    song.open(filename, std::ofstream::app);
    song << "\n\t}\n};\n\n#endif";
    song.close();
}