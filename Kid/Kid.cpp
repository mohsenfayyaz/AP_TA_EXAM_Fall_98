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
}

void Kid::print_kid_condition() {
    std::string type_text;
    if(type == Angry)
        type_text = ANGRY;
    if(type == Peaceful)
        type_text = PEACEFUL;
    if(type == Coward)
        type_text = COWARD;

    std::cout << id << ", " << type_text << ", " << posx << ", " << posy << ", " << radius << ", " << anger
        << ", " << charisma << ", " << courage << std::endl;
}