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

//    std::cout << id << ", " << type_text << ", " << posx << ", " << posy << ", " << radius << ", " << anger
//        << ", " << charisma << ", " << courage << std::endl;
    std::cout << id << ", " << type_text << ", posx: " << posx << ", posY: " << posy << ", vx: " << vx << ", vY: " << vy << ", Radius: " << radius << ", " << anger
              << ", " << charisma << ", " << courage << std::endl;
}

void Kid::make_a_copy() {
    try {
        delete(old_kid_copy);
    }catch (_exception& e){}

    old_kid_copy = new Kid(*this);

}

void Kid::check_death(){
    if(anger >= DEATH_ANGER_LIMIT || radius <= DEATH_RADIUS_LIMIT)
        this->die();
}