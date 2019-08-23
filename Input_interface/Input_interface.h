//
// Created by Mohsen on 8/21/2019.
//

#ifndef INC_05_AP_TA_INPUT_INTERFACE_H
#define INC_05_AP_TA_INPUT_INTERFACE_H

#define ANGRY "Angry"
#define PEACEFUL "Peaceful"
#define COWARD "Coward"
#define FALSE "false"
#define TRUE "true"

#include <iostream>
#include <vector>
#include "../Kid/Kid.h"
#include "../Kid/Kid_angry.h"
#include "../Kid/Kid_peaceful.h"
#include "../Kid/Kid_coward.h"

class Input_interface {
public:
    static std::vector<Kid*>* read_kids_from_input();
};


#endif //INC_05_AP_TA_INPUT_INTERFACE_H
