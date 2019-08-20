#include <iostream>
#include <cstdlib>
#include "Map.h"

#define MAP_FILE_ADDRESS "../map.dat"

int main(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        int arg = atoi(argv[i]);
        std::cout << arg << "\n";
    }

    Map my_map(MAP_FILE_ADDRESS);

    return 0;
}