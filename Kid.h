//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_KID_H
#define INC_05_AP_TA_KID_H

#include "Kid_type.h"

class Kid {
protected:
    int id;
    Kid_type type;
    bool fragile;
    double posx, posy, vx, vy;
    int radius, anger, charisma, courage;
    Kid(int _id, Kid_type _type, bool _fragile, double _posx, double _posy, double _vx, double _vy, int _radius, int _anger, int _charisma, int _courage);

public:
    virtual void hit(Kid* other_kid){};

    int get_id(){ return id; }
    Kid_type get_type(){ return type; }
    int get_radius(){ return radius; }
    int get_anger(){ return anger; }
    int get_charisma(){ return charisma; }
    int get_courage(){ return courage; }

};


#endif //INC_05_AP_TA_KID_H
