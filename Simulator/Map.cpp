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
        while ( getline (my_file,line) ) {
            map_data.push_back(line);
        }
        my_file.close();
    }else{
        std::cerr << "Unable to open file";
    }
    std::reverse(map_data.begin(), map_data.end());
}

Collision_type Map::does_collide_to_walls(double posx, double posy, double radius) {
    Collision_type collision_type = no_collison;
    radius += COLLISION_MARGIN;
    if(is_point_in_walls(posx + radius, posy + radius) )
        collision_type = right_top;
    if(is_point_in_walls(posx + radius, posy - radius))
        collision_type = right_bottom;
    if(is_point_in_walls(posx - radius, posy + radius))
        collision_type = left_top;
    if(is_point_in_walls(posx - radius, posy - radius))
        collision_type = left_bottom;

    if(is_point_in_walls(posx + radius, posy))
        collision_type = right;
    if(is_point_in_walls(posx, posy - radius))
        collision_type = bottom;
    if(is_point_in_walls(posx, posy + radius))
        collision_type = top;
    if(is_point_in_walls(posx - radius, posy))
        collision_type = left;

    if(is_point_in_walls(posx + radius, posy) && is_point_in_walls(posx, posy + radius))
        collision_type = right_top;
    if(is_point_in_walls(posx, posy - radius) && is_point_in_walls(posx + radius, posy))
        collision_type = right_bottom;
    if(is_point_in_walls(posx - radius, posy) && is_point_in_walls(posx, posy + radius))
        collision_type = left_top;
    if(is_point_in_walls(posx - radius, posy) && is_point_in_walls(posx, posy - radius))
        collision_type = left_bottom;

    return collision_type;
}

bool Map::is_point_in_walls(double posx, double posy) {
    //std::cerr << posx << ":" << posy << std::endl;
    if(posx <= 1 || posx >= map_length || posy <= 1 || posy >= map_length)
        return true;
    else
        return (map_data[int(posy)][int(posx)] == WALL_CHAR);
}

void Map::draw_map_with_kids(std::vector<Kid>* kids){
    std::vector<std::string> new_map_data(map_data);
    for (int i = 0; i < kids->size(); ++i) {
        Rigid_body current_body = (*kids)[i];
        double posx = current_body.get_posx();
        double posy = current_body.get_posy();
        double radius = current_body.get_radius();
        for (int j = 0; j < radius; ++j) {
            new_map_data[int(posy)][int(posx)] = BODY_CHAR;
            new_map_data[int(posy)+j][int(posx)] = BODY_CHAR;
            new_map_data[int(posy)-j][int(posx)] = BODY_CHAR;
            new_map_data[int(posy)][int(posx)+j] = BODY_CHAR;
            new_map_data[int(posy)][int(posx)-j] = BODY_CHAR;
        }

    }
    print_map(new_map_data);
}

void Map::print_map(std::vector<std::string>& map){
    std::reverse(map.begin(), map.end());
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            if(map[i][j] == BLANK_CHAR){
                std::cout << " ";
            }else{
                std::cout << map[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << "-----------------" << std::endl;
}