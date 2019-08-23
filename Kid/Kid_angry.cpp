//
// Created by Mohsen on 8/21/2019.
//

#include "Kid_angry.h"

void Kid_angry::hit(Kid* other_kid){
    this->change_speed_by_momentum(other_kid);

    if(other_kid->get_anger() > ANGRY_CONDITION_1_ANGER_LIMIT)
        this->fight(other_kid);
    else if(other_kid->get_charisma() > ANGRY_CONDITION_2_CHARISMA_LIMIT && other_kid->get_courage() > ANGRY_CONDITION_2_COURAGE_LIMIT)
        this->negotiate(other_kid);
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
