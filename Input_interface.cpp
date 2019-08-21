//
// Created by Mohsen on 8/21/2019.
//

#include "Input_interface.h"

std::vector<Kid> Input_interface::read_kids_from_input() {
    std::vector<Kid> kids;
    int number_of_kids;
    int id;
    Kid_type type;
    bool fragile;
    double posx, posy, vx, vy;
    int radius, anger, charisma, courage;
    std::string fragile_text, type_text, comma;

    std::cin >> number_of_kids;
    for (int i = 0; i < number_of_kids; ++i){
        std::cin >> id >> comma >> type_text >> fragile_text >> posx >> comma >> posy >> comma >> vx >> comma >>
            vy >> comma >> radius >> comma >> anger >> comma >> charisma >> comma >> courage;
        type_text = type_text.substr(0, type_text.size()-1);
        fragile_text = fragile_text.substr(0, fragile_text.size()-1);

//        std::cerr << id << comma << type_text << fragile_text << posx << comma << vx << comma << vy << comma
//            << radius << comma << anger << comma << charisma << comma << courage << std::endl;

        if(fragile_text == TRUE){
            fragile = true;
        }else{
            fragile = false;
        }

        if(type_text == ANGRY){
            type = Angry;
            Kid_angry new_kid(id, type, fragile, posx, posy, vx, vy, radius, anger, charisma, courage);
            kids.push_back(new_kid);
        }else{

        }
    }
    return kids;
}