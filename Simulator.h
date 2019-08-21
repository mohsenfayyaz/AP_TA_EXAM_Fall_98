//
// Created by Mohsen on 8/20/2019.
//

#ifndef INC_05_AP_TA_SIMULATOR_H
#define INC_05_AP_TA_SIMULATOR_H

#include "vector"
#include "Kid.h"
#include "Map.h"

class Simulator {
private:
    Map* simulation_map;
    int time_step;
    int total_time;
    std::vector<Kid>* kids;
    int number_of_steps;
    bool compare_kid_id();
    int last_id;
public:
    Simulator(const char* map_address, int time_step, int total_time, std::vector<Kid>* kids);
    void run();
    void run_once();

    void simulate_walls_collision();

    void simulate_move_kids();
};


#endif //INC_05_AP_TA_SIMULATOR_H
