//
// Created by Mohsen on 8/23/2019.
//

#include "Kid_peaceful.h"

void Kid_peaceful::hit(Kid *old_other_kid, Kid *real_other_kid) {
    this->change_speed_by_momentum(old_other_kid);
    check_peaceful_kid_special_behaviors(old_other_kid, real_other_kid);
    check_peaceful_kid_properties_conditions();
    check_death_conditions();
}

void Kid_peaceful::negotiate(Kid* other_kid) {
    radius += (1-(other_kid->get_courage() + other_kid->get_charisma() )/200) * 0.8 * radius;
    courage -= PEACEFUL_CONDITION_1_COURAGE_DEC;
}

void Kid_peaceful::unite(Kid *old_other_kid, Kid *real_other_kid) {
    vx = (vx + old_other_kid->get_vx()) / 2;
    vy = (vy + old_other_kid->get_vx()) / 2;
    real_other_kid->set_vx(vx);
    real_other_kid->set_vy(vy);

    charisma += PEACEFUL_CONDITION_2_CHARISMA_COURAGE_INC;
    courage += PEACEFUL_CONDITION_2_CHARISMA_COURAGE_INC;

}

void Kid_peaceful::check_peaceful_kid_properties_conditions() {
    if(anger > PEACEFUL_KID_ANGER_LIMIT)
        anger = PEACEFUL_KID_ANGER_LIMIT;
    if(charisma < PEACEFUL_KID_CHARISMA_LIMIT)
        charisma = PEACEFUL_KID_CHARISMA_LIMIT;
    if(courage < PEACEFUL_KID_COURAGE_LIMIT)
        courage = PEACEFUL_KID_COURAGE_LIMIT;
}

void Kid_peaceful::check_peaceful_kid_special_behaviors(Kid *old_other_kid, Kid *real_other_kid) {
    if(old_other_kid->get_anger() > PEACEFUL_CONDITION_1_ANGER_LIMIT && old_other_kid->get_courage() > PEACEFUL_CONDITION_1_COURAGE_LIMIT)
        this->negotiate(old_other_kid);
    else if(old_other_kid->get_charisma() > PEACEFUL_CONDITION_2_CHARISMA_LIMIT && old_other_kid->get_courage() > PEACEFUL_CONDITION_2_COURAGE_LIMIT)
        this->unite(old_other_kid, real_other_kid);
}
