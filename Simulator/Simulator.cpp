//
// Created by Mohsen on 8/20/2019.
//

#include <algorithm>
#include "Simulator.h"
#include "../Kid/Kid_angry.h"
#include <typeinfo>

Simulator::Simulator(const char *map_address, int _time_step, int _total_time, std::vector<Kid*>* _kids) {
    simulation_map = new Map(map_address);
    kids = _kids;
    time_step = _time_step;
    total_time = _total_time;
    number_of_steps = total_time/time_step;
    std::sort(kids->begin(), kids->end(), Kid::compare_kid_id);
    last_id = kids->back()->get_id();
    current_step = 0;
    //std::cerr << (*kids)[0].get_id() << std::endl << (*kids)[1].get_id() << std::endl ;
}

void Simulator::run() {
    for (int i = 0; i < number_of_steps; ++i) {
        std::cout << std::endl << "-----------------" << std::endl;
        std::cout << SHARP_SIGN << current_step << std::endl;
        run_once();
        current_step++;
    }
}

void Simulator::run_once() {
    print_kids_condition();
    simulation_map->draw_map_with_kids(kids);

    simulate_walls_collision();
    simulate_kids_collision();
    simulate_move_kids();
}

void Simulator::simulate_walls_collision() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        double next_posx = kid->get_next_posx(time_step);
        double next_posy = kid->get_next_posy(time_step);
        double radius = kid->get_radius();
        Collision_type kid_collision_type = simulation_map->does_collide_to_walls(next_posx, next_posy, radius);
        kid->collide_with_wall(kid_collision_type);
    }
}

void Simulator::simulate_move_kids() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        kid->move(time_step);
    }
}

void Simulator::print_kids_condition() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        kid->print_kid_condition();
    }
}

void Simulator::simulate_kids_collision() {
    std::vector<Kid*> old_kids = copy_kids();

    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        for (int j = 0; j < kids->size(); ++j){
            Kid* old_other_kid = old_kids[j];
            if(kid->get_id() != old_other_kid->get_id()) {
                if(kid->does_collide_with_other_body(old_other_kid)){
                    std::cout << kid->get_id() << " hit " << old_other_kid->get_id() << std::endl;
                    kid->hit(old_other_kid);
                }
            }
        }
    }

    delete_copy_kids(old_kids);

}

std::vector<Kid*> Simulator::copy_kids(){
    std::vector<Kid*> old_kids(*kids);
    for (int i = 0; i < old_kids.size(); ++i) {
        Kid* kid_copy = new Kid(*old_kids[i]);
        old_kids[i] = kid_copy;
    }
    return old_kids;
}

void Simulator::delete_copy_kids(std::vector<Kid*>& copy_kids) {
    for (int i = 0; i < copy_kids.size(); ++i) {
        delete(copy_kids[i]);
    }
    copy_kids.clear();
}