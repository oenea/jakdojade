#include "town.h"
#include <iostream>
#include <string.h>

bool is_bound(const int32_t i, const int32_t w){
    return ( (i >= 0) && (i < w) );
}

bool is_bound(const int32_t i, const int32_t w, const int32_t h){
    return ( (i >= 0) && (i < w*h) );
}

void input_town(char* map, char* towns, const uint32_t town_count, const uint32_t longest_town_name, const uint32_t w, const uint32_t h) {
	char* temp_towns = new char[town_count * longest_town_name];
	pos_t* first_last_pos = new pos_t[town_count * longest_town_name];

    uint32_t last_town = 0, j = 0;
    for (uint32_t i = 0; i < (w * h); i++) {
        if ( isalnum(map[i]) ) {
            first_last_pos[last_town].x = i;
            j = 0;
            do {
                temp_towns[(last_town * longest_town_name) + j] = map[i];
                i += 1;
                j += 1;
            } while ( isalnum(map[i]) && (i % w != 0) );
            first_last_pos[last_town].y = (i - 1);
            temp_towns[(last_town * longest_town_name) + j] = '\0';
            last_town += 1;
        }
    }
    
    for(uint32_t i = 0; i < (w * h); i++) {
        towns[i * longest_town_name] = '\0';
    }
    for (uint32_t i = 0; i < town_count; i++) {
        int32_t pos = town_position(map, first_last_pos[i].x, w, h);
        if (pos == -1) {
            pos = town_position(map, first_last_pos[i].y, w, h);
        }

        strncpy(&towns[pos * longest_town_name], &temp_towns[i * longest_town_name], strlen(&temp_towns[i * longest_town_name]));
        towns[(pos * longest_town_name) + strlen(&temp_towns[i * longest_town_name])] = '\0';  
    }

	delete[] temp_towns;
	delete[] first_last_pos;
}


void get_town_info(char* map, const uint32_t vertices, uint32_t& town_count, uint32_t& longest_town_name) {
    bool is_town = false;
    town_count = 0;
    longest_town_name = 0;
    uint32_t temp = 0;
    for (uint32_t i = 0; i < vertices; i++){
        if(map[i] == '*'){
            town_count += 1;  
        }
        if (is_town == false) {
            if ( isalnum(map[i]) ) {
                temp = 1;
                is_town = true;    
            }
        } else if (is_town == true) {
            if ( isalnum(map[i]) ) {
                temp += 1;  
            } else {
                is_town = false;
            }              
        }
        if (temp > longest_town_name) {
            longest_town_name = temp;
        }
    }
}

int32_t town_position(char* map, int32_t vertex, const int32_t w, const int32_t h){
    static const pos_t town_offset[8] = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}
    };
    int32_t x = (vertex / w);
    int32_t y = (vertex % w);
   
    for(uint8_t j = 0; j < 8; j++){
        if(is_bound(town_offset[j].x + x, w) && is_bound(town_offset[j].y + y, w)){
            int32_t temp = ((town_offset[j].x + x) * w + (town_offset[j].y + y));
            if(is_bound(temp, w, h)){
                if(map[ temp ] == '*'){
                    return temp;     
                }
            }
        }
    }
    return -1;
}
  

uint32_t hashed(char* input, const uint32_t hash_table_size) {
    int32_t hash = 0x811c9dc5;
    for(uint32_t i = 0; i < uint32_t(strlen(input)); i++){
        hash = hash ^ int32_t(input[i]);
        hash = hash * 0x01000193;
    }
    return uint32_t(hash % hash_table_size);
}

/*
uint32_t hashed3(char* input, const uint32_t HASH_TABLE_BUCKET_IN_BUCKET_SIZE) {
    uint32_t hash = (input[0] % 3);
    for(uint32_t i = 1; i < uint32_t(strlen(input)); i++){
        if(isdigit(input[i])) {
            hash += 36 * i * (input[i] - 48);
        } else {
            hash += 36 * i * (input[i] - 65 + 10);
        }
    }
    return uint32_t(hash % HASH_TABLE_BUCKET_IN_BUCKET_SIZE);
}*/
/*

uint32_t hashed2(char* input, const uint32_t HASH_TABLE_SIZE) {
    uint32_t hash = 0;
    for(uint32_t i = 0; i < uint32_t(strlen(input)); i++){
    hash += input[i];
    hash *= 0x5bd1e995;
    hash ^= input[i] >> 15;
  }
  return uint32_t(hash % HASH_TABLE_SIZE);
}      
*/
/*
uint32_t max_town_index(vector<town_t> const &town){
    uint32_t maximum = 0;
    for(uint32_t i = 0; i < uint32_t(town.size()); i++){
        if(int32_t(maximum) < town[i].vertex){
            maximum = town[i].vertex;
        }
    }
    return maximum;
}

void fill_towns(vector<string> &towns, vector<town_t> const &temp_towns){
    for(uint32_t i = 0; i < uint32_t(temp_towns.size()); i++){
        towns[temp_towns[i].vertex] = temp_towns[i].name;
    }
}*/