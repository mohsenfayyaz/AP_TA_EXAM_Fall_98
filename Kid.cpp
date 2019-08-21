//
// Created by Mohsen on 8/21/2019.
//

#include "Kid.h"

Kid::Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, int _radius, int _anger, int _charisma, int _courage)
    :Rigid_body(_posx, _posy, _vx, _vy, _radius, _fragile){
    id = _id;
    type = _type;
    anger = _anger;
    charisma = _charisma;
    courage = _courage;
}