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
    //std::cerr << (*kids)[0].get_id() << std::endl << (*kids)[1].get_id() << std::endl ;
}

void Simulator::run() {
    for (int i = 0; i < number_of_steps; ++i) {
        run_once();
    }
}

void Simulator::run_once() {
    simulate_move_kids();
    simulate_walls_collision();

}

void Simulator::simulate_walls_collision() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = &((*kids)[i]);
        int posx = kid->get_posx();
        int posy = kid->get_posy();
        int radius = kid->get_radius();
        Collision_type kid_collision_type = simulation_map->does_collide_to_walls(posx, posy, radius);
        if(kid_collision_type == right){
            //kid->collide_right();
        }
    }
}

void Simulator::simulate_move_kids() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = &((*kids)[i]);
        kid->move(time_step);
    }
}
