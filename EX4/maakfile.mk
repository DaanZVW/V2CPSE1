decompressor: compressor.cpp compressor.hpp decompressor.hpp wilhelmus.txt
	g++ -std=c++17 compressor.cpp compressor.hpp decompressor.hpp -o decompressor
	./decompressor