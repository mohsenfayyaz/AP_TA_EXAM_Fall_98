//
// Created by Mohsen on 8/21/2019.
//

#include "Kid_angry.h"

void Kid_angry::hit(Kid *old_other_kid, Kid *real_other_kid) {
    if(!check_angry_kid_special_behaviors(old_other_kid))
        this->change_speed_by_momentum(old_other_kid);
    check_angry_kid_properties_conditions();
    check_death_conditions();
}

void Kid_angry::fight(Kid* other_kid){
    if(this->radius < other_kid->get_radius()){
        radius = radius * ANGRY_CONDITION_1_RADIUS_PERCENT;
        anger += ANGRY_CONDITION_1_ANGER_ADDITION;
    }
}

void Kid_angry::negotiate(Kid* other_kid) {
    radius += (1-(other_kid->get_courage() + other_kid->get_charisma() )/200) * 0.8 * radius;
}

void Kid_angry::check_angry_kid_properties_conditions() {
    if(anger < ANGRY_KID_ANGER_LIMIT)
        anger = ANGRY_KID_ANGER_LIMIT;
    charisma = ANGRY_KID_CHARISMA_LIMIT;
    if(courage < ANGRY_KID_COURAGE_LIMIT)
        courage = ANGRY_KID_COURAGE_LIMIT;
}

bool Kid_angry::check_angry_kid_special_behaviors(Kid *old_other_kid) {
    if(old_other_kid->get_anger() > ANGRY_CONDITION_1_ANGER_LIMIT) {
        this->fight(old_other_kid);
        return true;
    }else if(old_other_kid->get_charisma() > ANGRY_CONDITION_2_CHARISMA_LIMIT && old_other_kid->get_courage() > ANGRY_CONDITION_2_COURAGE_LIMIT) {
        this->negotiate(old_other_kid);
        return true;
    }
    return false;
}
