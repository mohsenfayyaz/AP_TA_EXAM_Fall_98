//
// Created by Mohsen on 8/23/2019.
//

#ifndef INC_05_AP_TA_KID_COWARD_H
#define INC_05_AP_TA_KID_COWARD_H


#include "Kid_type.h"
#include "Kid.h"

#define COWARD_ANGER_INC 5
#define COWARD_CONDITION_1_ANGER_LIMIT 70

class Kid_coward : public Kid {
public:
    Kid_coward(int id, Kid_type type, bool fragile, double posx, double posy, double vx, double vy, double radius,
               int anger, int charisma, int courage) : Kid(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage) {}

    void hit(Kid *old_other_kid, Kid *real_other_kid);
};


#endif //INC_05_AP_TA_KID_COWARD_H
