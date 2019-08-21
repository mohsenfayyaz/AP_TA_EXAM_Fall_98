//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_KID_ANGRY_H
#define INC_05_AP_TA_KID_ANGRY_H

#include "Kid.h"
#include "Kid_type.h"

class Kid_angry : public Kid {
public:
    Kid_angry(int id, Kid_type type, bool fragile, double posx, double posy, double vx, double vy, int radius,
              int anger, int charisma, int courage) : Kid(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage) {}

    void hit(Kid* other_kid);
};


#endif //INC_05_AP_TA_KID_ANGRY_H
