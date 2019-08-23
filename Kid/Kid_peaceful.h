//
// Created by Mohsen on 8/23/2019.
//

#ifndef INC_05_AP_TA_KID_PEACEFUL_H
#define INC_05_AP_TA_KID_PEACEFUL_H

#include "Kid.h"

#define PEACEFUL_CONDITION_1_ANGER_LIMIT 70
#define PEACEFUL_CONDITION_1_COURAGE_LIMIT 50
#define PEACEFUL_CONDITION_1_COURAGE_DEC 10

#define PEACEFUL_CONDITION_2_COURAGE_LIMIT 30
#define PEACEFUL_CONDITION_2_CHARISMA_LIMIT 50
#define PEACEFUL_CONDITION_2_CHARISMA_COURAGE_INC 2

#define PEACEFUL_KID_ANGER_LIMIT 30
#define PEACEFUL_KID_CHARISMA_LIMIT 50
#define PEACEFUL_KID_COURAGE_LIMIT 30

class Kid_peaceful : public Kid {
private:
    void negotiate(Kid *other_kid);
    void unite(Kid *old_other_kid, Kid *real_other_kid);
    void check_peaceful_kid_properties_conditions();

public:
    Kid_peaceful(int id, Kid_type type, bool fragile, double posx, double posy, double vx, double vy, double radius,
              int anger, int charisma, int courage) : Kid(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage) {}

    void hit(Kid *old_other_kid, Kid *real_other_kid);
};


#endif //INC_05_AP_TA_KID_PEACEFUL_H
