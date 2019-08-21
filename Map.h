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

#define WALL_CHAR 'b'
#define BLANK_CHAR 'w'

class Map {
private:
    std::vector<std::string> map_data;
    int map_length;
public:
    explicit Map(const char *file_address);
    Collision_type does_collide_to_walls(double posx, double posy, int radius);

    bool is_point_in_walls(double posx, double posy);
};


#endif //INC_05_AP_TA_MAP_H
