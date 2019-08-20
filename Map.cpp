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
}