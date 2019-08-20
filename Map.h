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

class Map {
private:
    std::vector<std::string> map_data;
    int map_length;
public:
    explicit Map(const char *file_address);

};


#endif //INC_05_AP_TA_MAP_H
