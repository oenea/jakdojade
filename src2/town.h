#ifndef TOWN_H
#define TOWN_H

#include "structs.h"

using namespace std;

bool is_bound(const int32_t i, const int32_t w, const int32_t h);
bool is_bound(const int32_t i , const int32_t w);
void input_town(char* map, char* towns, const uint32_t town_count, const uint32_t longest_town_name, const uint32_t w, const uint32_t h);
void get_town_info(char* map, const uint32_t vertices, uint32_t& town_count, uint32_t& longest_town_name);
int32_t town_position(char* map, int32_t vertex, int32_t w, int32_t h);
uint32_t hashed(char* input, const uint32_t hash_table_size);


//uint32_t hashed2(char* input, const uint32_t HASH_TABLE_SIZE);
//uint32_t hashed3(char* input, const uint32_t HASH_TABLE_BUCKET_IN_BUCKET_SIZE);
//uint32_t max_town_index(vector<town_t> const &town);
//void fill_towns(vector<string> &towns, vector<town_t> const &temp_towns);
#endif /* TOWN_H */