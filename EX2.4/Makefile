#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += song.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due



song.hpp: generator
	./generator

generator: generate.o generate_song.o rtttl_player.o
	g++ -std=c++17 generate.o generate_song.o rtttl_player.o -o generator

generate.o: generate.cpp rtttl_player.hpp generate_song.hpp
	g++ -std=c++17 -c generate.cpp -o generate.o

generate_song.o: generate_song.hpp generate_song.cpp
	g++ -std=c++17 -c generate_song.cpp -o generate_song.o

rtttl_player.o: rtttl_player.hpp rtttl_player.cpp
	g++ -std=c++17 -c rtttl_player.cpp -o rtttl_player.o


