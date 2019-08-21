//
// Created by Mohsen on 8/20/2019.
//

#include "Map.h"

Map::Map(const char *file_address) {
    std::string line;
    std::ifstream my_file (file_address);
    if (my_file.is_open()){
        getline (my_file,line);
        map_length = atoi(line.c_str());
        while ( getline (my_file,line) )
        {
            std::cout << line << '\n';
            map_data.push_back(line);
        }
        my_file.close();
    }else{
        std::cerr << "Unable to open file";
    }
    std::reverse(map_data.begin(), map_data.end());
}

Collision_type Map::does_collide_to_walls(double posx, double posy, int radius) {
    Collision_type collision_type = no_collison;
    if(is_point_in_walls(posx + radius, posy)){
        collision_type = right;
    }
    if(is_point_in_walls(posx + radius, posy + radius)){
        collision_type = right_top;
    }
    if(is_point_in_walls(posx + radius, posy - radius)){
        collision_type = right_bottom;
    }
    if(is_point_in_walls(posx, posy - radius)){
        collision_type = top;
    }
    if(is_point_in_walls(posx, posy + radius)){
        collision_type = bottom;
    }
    if(is_point_in_walls(posx - radius, posy)){
        collision_type = left;
    }
    if(is_point_in_walls(posx - radius, posy + radius)){
        collision_type = left_top;
    }
    if(is_point_in_walls(posx - radius, posy - radius)){
        collision_type = left_bottom;
    }

    return collision_type;
}

bool Map::is_point_in_walls(double posx, double posy) {
    //std::cerr << posx << ":" << posy << std::endl;
    return (map_data[int(posy)][int(posx)] == WALL_CHAR);
}
