//
// Created by Mohsen on 8/21/2019.
//

#include "Kid.h"

Kid::Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, double _radius, int _anger, int _charisma, int _courage)
    :Rigid_body(_posx, _posy, _vx, _vy, _radius, _fragile){
    id = _id;
    type = _type;
    anger = _anger;
    charisma = _charisma;
    courage = _courage;
    dead = false;
}

void Kid::print_kid_condition() {
    std::string type_text;
    if(type == Angry)
        type_text = ANGRY;
    if(type == Peaceful)
        type_text = PEACEFUL;
    if(type == Coward)
        type_text = COWARD;

    std::cout << id << ", " << type_text << ", " << set_precision(posx, 1) << ", " << set_precision(posy, 1) << ", " << set_precision(radius, 1) << ", " << anger
        << ", " << charisma << ", " << courage << std::endl;
//    std::cout << id << ", " << type_text << ", posx: " << posx << ", posY: " << posy << ", vx: " << vx << ", vY: " << vy << ", Radius: " << radius << ", " << anger
//              << ", " << charisma << ", " << courage << std::endl;
}

double Kid::set_precision(double num, int precision){
    double precision_10 = pow(10, precision);
    return floor(num * precision_10) / precision_10;
}

void Kid::check_death_conditions(){
    if(anger >= DEATH_ANGER_LIMIT || radius <= DEATH_RADIUS_LIMIT)
        this->die();
}

bool Kid::does_break(Kid* old_other_kid) {
    if(this->is_fragile() && radius + old_other_kid->get_radius() > BREAKING_RADIUS_LIMIT){
        if(radius < BREAKING_DEATH_RADIUS_LIMIT){
            this->die();
        }else{
            return true;
        }
    }
    return false;
}

void Kid::unite_peaceful_friends(int num_of_friends){
    courage += num_of_friends * PEACEFUL_UNION_FACTOR;
}

bool Kid::compare_kid_id(const Kid *lhs, const Kid *rhs){
    return (lhs->get_id() < rhs->get_id());
}