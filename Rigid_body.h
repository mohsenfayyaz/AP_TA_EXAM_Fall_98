//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_RIGID_BODY_H
#define INC_05_AP_TA_RIGID_BODY_H


class Rigid_body {
protected:
    double posx, posy, vx, vy;
    int radius;
    bool fragile;
public:
    Rigid_body(double posx, double posy, double vx, double vy, int radius, bool fragile);
    int get_radius(){ return radius; }
    double get_posx(){ return posx; }
    double get_posy(){ return posy; }
    void move(int time_step);
};


#endif //INC_05_AP_TA_RIGID_BODY_H
