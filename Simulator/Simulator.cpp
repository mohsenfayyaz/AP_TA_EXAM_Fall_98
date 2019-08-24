//
// Created by Mohsen on 8/20/2019.
//

#include <algorithm>
#include "Simulator.h"
#include "../Kid/Kid_angry.h"

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
    check_kids_death();
    sweep_dead_kids();
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
    std::vector<std::vector<Kid*> > collisions = find_kids_collisions();
    simulate_kids_hit_each_other(collisions);
    simulate_fragility(collisions);
    simulate_peaceful_kids_union(collisions);
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

void Simulator::sweep_dead_kids() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        if(kid->is_dead()){
            std::cout << kid->get_id() << " died :(";
            delete(kid);
            kids->erase(kids->begin() + i);
        }
    }
}

std::vector<std::vector<Kid*> > Simulator::find_kids_collisions() {
    std::vector<std::vector<Kid*> > collisions;
    for (int i = 0; i < kids->size(); ++i) {
        std::vector<Kid*> collisions_of_i_th_kid;
        collisions.push_back(collisions_of_i_th_kid);
        Kid* kid = (*kids)[i];
        for (int j = 0; j < kids->size(); ++j){
            Kid* other_kid = (*kids)[j];
            if(kid->get_id() != other_kid->get_id()) {
                if(kid->does_collide_with_other_body(other_kid)){
                    //std::cout << kid->get_id() << " hit " << old_other_kid->get_id() << std::endl;
                    collisions[i].push_back(other_kid);
                }
            }
        }
    }
    return collisions;
}

void Simulator::simulate_kids_hit_each_other(std::vector<std::vector<Kid *> > collisions) {
    std::vector<Kid*> old_kids = copy_kids();
    for (int i = 0; i < collisions.size(); ++i) {
        Kid* kid = (*kids)[i];
        for (int j = 0; j < collisions[i].size(); ++j) {
            Kid* old_other_kid = find_old_kid( old_kids, collisions[i][j]->get_id() );
            std::cout << kid->get_id() << " hit " << old_other_kid->get_id() << std::endl;
            kid->hit(old_other_kid, collisions[i][j]);
        }
    }
    delete_copy_kids(old_kids);
}

Kid* Simulator::find_old_kid(std::vector<Kid*> &old_kids, int id){
    for (int i = 0; i < old_kids.size(); ++i) {
        if(old_kids[i]->get_id() == id)
            return old_kids[i];
    }
    return NULL;
}

void Simulator::simulate_fragility(std::vector<std::vector<Kid *> > collisions) {
    std::vector<Kid*> old_kids = copy_kids();
    for (int i = 0; i < collisions.size(); ++i) {
        Kid* kid = (*kids)[i];
        for (int j = 0; j < collisions[i].size(); ++j){
            Kid* old_other_kid = find_old_kid( old_kids, collisions[i][j]->get_id() );
            if( kid->does_break(old_other_kid))
                break_to_six(kid);
        }
    }
    delete_copy_kids(old_kids);
}

void Simulator::break_to_six(Kid *kid) {
    double old_v = sqrt(pow(kid->get_vx(), 2) + pow(kid->get_vy(), 2));
    double new_v = old_v * BREAK_SPEED_RATIO;
    double vx = new_v * cos(BREAKING_DEGREE * PI/180);
    double vy = new_v * sin(BREAKING_DEGREE * PI/180);
    kids->push_back( make_a_broken_kid_copy(kid, +new_v, 0) );
    kids->push_back( make_a_broken_kid_copy(kid, -new_v, 0) );
    kids->push_back( make_a_broken_kid_copy(kid, vx, vy) );
    kids->push_back( make_a_broken_kid_copy(kid, -vx, vy) );
    kids->push_back( make_a_broken_kid_copy(kid, -vx, -vy) );
    kids->push_back( make_a_broken_kid_copy(kid, vx, -vy) );
    kid->die();
}

Kid* Simulator::make_a_broken_kid_copy(Kid* kid, double vx, double vy){
    double new_radius = kid->get_radius() * BREAK_RADIUS_RATIO;
    Kid* new_kid = kid->copy_yourself();
    new_kid->set_id(++last_id);
    new_kid->set_radius(new_radius);
    new_kid->set_vx(vx);
    new_kid->set_vy(vy);

    return new_kid;
}

void Simulator::check_kids_death() {
    for (int i = 0; i < kids->size(); ++i) {
        Kid* kid = (*kids)[i];
        kid->check_death_conditions();
    }
}

void Simulator::simulate_peaceful_kids_union(std::vector<std::vector<Kid *> > collisions) {
    for (int i = 0; i < collisions.size(); ++i) {
        Kid* kid = (*kids)[i];
        int peaceful_collisions_counter = 0;
        if(kid->get_type() == Peaceful) {
            for (int j = 0; j < collisions[i].size(); ++j) {
                Kid *other_kid = collisions[i][j];
                if (kid->get_type() == Peaceful)
                    peaceful_collisions_counter++;
            }
            if(peaceful_collisions_counter > PEACEFUL_UNION_COUNT_LIMIT)
                kid->unite_peaceful_friends(peaceful_collisions_counter);
        }
    }
}
