//
// Created by Mohsen on 8/20/2019.
//

#ifndef INC_05_AP_TA_SIMULATOR_H
#define INC_05_AP_TA_SIMULATOR_H

#include "vector"
#include "../Kid/Kid.h"
#include "../Map/Map.h"
#include "../Kid/Kid_angry.h"
#include <algorithm>

#define SHARP_SIGN '#'
#define DEATH_COUT ", KIA"

#define BREAK_RADIUS_RATIO 1/3
#define BREAK_SPEED_RATIO 1/6
#define BREAKING_DEGREE 60
#define PI 3.14159265
#define PEACEFUL_UNION_COUNT_LIMIT 2

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
    void sweep_dead_kids();
    std::vector<std::vector<Kid*> > find_kids_collisions();
    void simulate_kids_hit_each_other(std::vector<std::vector<Kid *> > collisions);
    void simulate_fragility(std::vector<std::vector<Kid *> > collisions);
    void break_to_six(Kid *kid);
    Kid *make_a_broken_kid_copy(Kid *kid, double vx, double vy);
    Kid *find_old_kid(std::vector<Kid *> &old_kids, int id);
    void check_kids_death();
    void simulate_peaceful_kids_union(std::vector<std::vector<Kid *> > collisions);

public:
    Simulator(const char* map_address, int time_step, int total_time, std::vector<Kid*>* kids);
    void run();
    void run_once();

};


#endif //INC_05_AP_TA_SIMULATOR_H
