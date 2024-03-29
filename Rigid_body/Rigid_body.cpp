//
// Created by Mohsen on 8/21/2019.
//

#include "Rigid_body.h"

Rigid_body::Rigid_body(double _posx, double _posy, double _vx, double _vy, double _radius, bool _fragile) {
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

void Rigid_body::collide_with_wall(Collision_type kid_collision_type){
    if(kid_collision_type == right || kid_collision_type == left){
        vx = -vx;
    }
    if(kid_collision_type == top || kid_collision_type == bottom){
        vy = -vy;
    }
    double v2 = pow(vx, 2) + pow(vy, 2);
    double new_vxy_45 = sqrt(v2/2);
    if(kid_collision_type == right_bottom){
        vx = -new_vxy_45;
        vy = +new_vxy_45;
    }
    if(kid_collision_type == right_top){
        vx = -new_vxy_45;
        vy = -new_vxy_45;
    }
    if(kid_collision_type == left_bottom){
        vx = +new_vxy_45;
        vy = +new_vxy_45;
    }
    if(kid_collision_type == left_top){
        vx = +new_vxy_45;
        vy = -new_vxy_45;
    }
}

bool Rigid_body::does_collide_with_other_body(Rigid_body* other_body){
    double centers_distance = sqrt( pow(this->posx - other_body->get_posx(), 2) + pow(this->posy - other_body->get_posy(), 2) );
    return ( centers_distance <= this->radius + other_body->get_radius() );
}

void Rigid_body::change_speed_by_momentum(Rigid_body* other_body){
    double r1_2 = pow(radius, 2);
    double r2_2 = pow(other_body->get_radius(), 2);
    vx = ((r1_2-r2_2) / (r1_2+r2_2)) * vx + 2*r2_2 / (r1_2+r2_2) * other_body->get_vx();
    vy = ((r1_2-r2_2) / (r1_2+r2_2)) * vy + 2*r2_2 / (r1_2+r2_2) * other_body->get_vy();
}