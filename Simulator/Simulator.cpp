//
// Created by Mohsen on 8/20/2019.
//

#include <algorithm>
#include "Simulator.h"

Simulator::Simulator(const char *map_address, int _time_step, int _total_time, std::vector<Kid>* _kids) {
    simulation_map = new Map(map_address);
    kids = _kids;
    time_step = _time_step;
    total_time = _total_time;
    number_of_steps = total_time/time_step;
    std::sort(kids->begin(), kids->end(), Kid::compare_kid_id);
    last_id = kids->back().get_id();
    current_step = 0;
    //std::cerr << (*kids)[0].get_id() << std::endl << (*kids)[1].get_id() << std::endl ;
}

void Simulator::run() {
    for (int i = 0; i < number_of_steps; ++i) {
        std::cout << SHARP_SIGN << current_step << std::endl;
        run_once();
        current_step++;
    }
}

void Simulator::run_once() {
    print_kids_condition();
    simulation_map->draw_map_with_kids(kids);


    simulate_move_kids();
    simulate_walls_collision();
}

void Simulator::simulate_walls_collision() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = &((*kids)[i]);
        double next_posx = kid->get_next_posx(time_step);
        double next_posy = kid->get_next_posy(time_step);
        int radius = kid->get_radius();
        Collision_type kid_collision_type = simulation_map->does_collide_to_walls(next_posx, next_posy, radius);
        kid->collide_with_wall(kid_collision_type);
    }
}

void Simulator::simulate_move_kids() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = &((*kids)[i]);
        kid->move(time_step);
    }
}

void Simulator::print_kids_condition() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = &((*kids)[i]);
        kid->print_kid_condition();
    }
}
