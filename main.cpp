#include <cstdlib>
#include "Simulator/Simulator.h"
#include "Input_interface.h"

#define MAP_FILE_ADDRESS "../map.dat"

int main(int argc, char** argv) {
    int time_step = atoi(argv[1]);
    int total_time = atoi(argv[2]);
    std::vector<Kid> kids = Input_interface::read_kids_from_input();
    Simulator my_simulator(MAP_FILE_ADDRESS, time_step, total_time, &kids);
    my_simulator.run();

    return 0;
}