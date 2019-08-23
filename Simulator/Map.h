//
// Created by Mohsen on 8/20/2019.
//

#ifndef INC_05_AP_TA_MAP_H
#define INC_05_AP_TA_MAP_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "Collision_type.h"
#include "../Kid/Rigid_body.h"
#include "../Kid/Kid.h"

#define WALL_CHAR 'b'
#define BLANK_CHAR 'w'
#define BODY_CHAR '#'
#define COLLISION_MARGIN .1

class Map {
private:
    std::vector<std::string> map_data;
    int map_length;
    void print_map(std::vector<std::string> &map);
public:
    explicit Map(const char *file_address);

    Collision_type does_collide_to_walls(double posx, double posy, double radius);
    bool is_point_in_walls(double posx, double posy);
    void draw_map_with_kids(std::vector<Kid*> *kids);


};


#endif //INC_05_AP_TA_MAP_H
