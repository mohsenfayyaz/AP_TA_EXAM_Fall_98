//
// Created by Mohsen on 8/23/2019.
//

#include "Kid_coward.h"

void Kid_coward::hit(Kid *old_other_kid, Kid *real_other_kid) {
    this->change_speed_by_momentum(old_other_kid);
    anger += COWARD_ANGER_INC;

    if(old_other_kid->get_anger() > COWARD_CONDITION_1_ANGER_LIMIT)
        this->die();

    check_coward_kid_properties_conditions();
}

void Kid_coward::check_coward_kid_properties_conditions() {
    if(anger < COWARD_KID_ANGER_LIMIT)
        anger = COWARD_KID_ANGER_LIMIT;
    charisma = COWARD_KID_CHARISMA_LIMIT;
    courage = COWARD_KID_COURAGE_LIMIT;
}
