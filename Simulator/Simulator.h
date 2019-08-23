//
// Created by Mohsen on 8/20/2019.
//

#ifndef INC_05_AP_TA_SIMULATOR_H
#define INC_05_AP_TA_SIMULATOR_H

#include "vector"
#include "../Kid/Kid.h"
#include "Map.h"

#define SHARP_SIGN '#'

class Simulator {
private:
    Map* simulation_map;
    int time_step;
    int total_time;
    std::vector<Kid*>* kids;
    int number_of_steps;
    int current_step;
    bool compare_kid_id();
    int last_id;
    void simulate_kids_collision();
    void simulate_move_kids();
    void simulate_walls_collision();
    void print_kids_condition();
    std::vector<Kid *> copy_kids();
    void delete_copy_kids(std::vector<Kid *> &copy_kids);
public:
    Simulator(const char* map_address, int time_step, int total_time, std::vector<Kid*>* kids);
    void run();
    void run_once();

};


#endif //INC_05_AP_TA_SIMULATOR_H
