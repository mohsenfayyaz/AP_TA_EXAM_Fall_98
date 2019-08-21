//
// Created by Mohsen on 8/21/2019.
//

#include "Rigid_body.h"

Rigid_body::Rigid_body(double _posx, double _posy, double _vx, double _vy, int _radius, bool _fragile) {
    posx = _posx;
    posy = _posy;
    vx = _vx;
    vy = _vy;
    radius = _radius;
    fragile = _fragile;
}

void Rigid_body::move(int time_step) {
    posx = posx + vx * time_step;
    posy = posy + vy * time_step;
}