//
// Created by Mohsen on 8/21/2019.
//

#include "Input_interface.h"

std::vector<Kid*>* Input_interface::read_kids_from_input() {
    int id, radius, anger, charisma, courage;
    bool fragile;
    double posx, posy, vx, vy;
    Kid_type type;
    std::string fragile_text, type_text, comma;
    std::vector<Kid*>* kids = new std::vector<Kid*>;

    //std::cin >> number_of_kids;
    while(std::cin >> id >> comma >> type_text >> fragile_text >> posx >> comma >> posy >> comma >> vx >> comma >>
                   vy >> comma >> radius >> comma >> anger >> comma >> charisma >> comma >> courage){
        type_text = type_text.substr(0, type_text.size()-1);
        fragile_text = fragile_text.substr(0, fragile_text.size()-1);
        fragile = (fragile_text == TRUE);
        if(type_text == ANGRY){
            type = Angry;
            Kid_angry* new_kid = new Kid_angry(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage);
            kids->push_back(new_kid);
        }else{

        }
    }
    return kids;
}