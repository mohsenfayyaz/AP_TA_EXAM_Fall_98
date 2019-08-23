//
// Created by Mohsen on 8/23/2019.
//

#include "Kid_coward.h"

void Kid_coward::hit(Kid *old_other_kid, Kid *real_other_kid) {
    this->change_speed_by_momentum(old_other_kid);
    anger += COWARD_ANGER_INC;

    if(old_other_kid->get_anger() > COWARD_CONDITION_1_ANGER_LIMIT)
        this->die();
}