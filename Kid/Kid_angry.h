//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_KID_ANGRY_H
#define INC_05_AP_TA_KID_ANGRY_H

#include "Kid.h"
#include "Kid_type.h"

#define ANGRY_CONDITION_1_ANGER_LIMIT 70
#define ANGRY_CONDITION_1_RADIUS_PERCENT 0.8
#define ANGRY_CONDITION_1_ANGER_ADDITION 5

#define ANGRY_CONDITION_2_COURAGE_LIMIT 30
#define ANGRY_CONDITION_2_CHARISMA_LIMIT 50

#define ANGRY_KID_ANGER_LIMIT 70
#define ANGRY_KID_CHARISMA_LIMIT 20
#define ANGRY_KID_COURAGE_LIMIT 70

class Kid_angry : public Kid {
private:
    void fight(Kid *other_kid);
    void negotiate(Kid* other_kid);
    void check_angry_kid_properties_conditions();
    bool check_angry_kid_special_behaviors(Kid *old_other_kid);

public:
    Kid_angry(int id, Kid_type type, bool fragile, double posx, double posy, double vx, double vy, double radius,
              int anger, int charisma, int courage) : Kid(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage) {}

    void hit(Kid *old_other_kid, Kid *real_other_kid);
};


#endif //INC_05_AP_TA_KID_ANGRY_H
