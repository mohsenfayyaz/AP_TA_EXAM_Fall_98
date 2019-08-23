//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_RIGID_BODY_H
#define INC_05_AP_TA_RIGID_BODY_H

#include "../Simulator/Collision_type.h"
#include <cmath>
#include <iostream>

class Rigid_body {
protected:
    double posx, posy, vx, vy;
    double radius;
    bool fragile;

    void change_speed_by_momentum(Rigid_body *other_body);
public:
    Rigid_body(double posx, double posy, double vx, double vy, double radius, bool fragile);
    double get_radius(){ return radius; }
    double get_posx(){ return posx; }
    double get_posy(){ return posy; }
    double get_vx(){ return vx; }
    double get_vy(){ return vy; }
    double get_next_posx(int time_step){ return posx + vx * time_step; }
    double get_next_posy(int time_step){ return posy + vy * time_step; }
    void move(int time_step);

    void collide_with_wall(Collision_type kid_collision_type);
    bool does_collide_with_other_body(Rigid_body* other_body);


};


#endif //INC_05_AP_TA_RIGID_BODY_H
