/*!
    \file
    \brief Файл реализации класса хэш таблицы
*/

#include "HTable.h"

HNode::HNode(flatsData data){
    this->data = data;
    this->key = data.getName();
}

HTable::HTable(int size){


    this->table = vector<vector< HNode* >> (size, vector<HNode*>(0));    
    this->size = size;
}

unsigned int HTable::hash(string &key){
    unsigned int hash = 0;

    for (int i = 0; i < key.size(); i++){
        hash = (hash*1664525) + (unsigned char)(key[i]) + 1013904223;
    }

    return hash % size;
}

void HTable::insertData(flatsData data){
    string key = data.getName();
    int hs = hash(key);
    table[hs].push_back(new HNode(data));
}

bool HTable::findData(string key){
    int hs = hash(key);
    return table[hs].size() != 0;
}


int HTable::countCollisions(){
    int count = 0;
    for (int i = 0; i < size; i++){
        if (table[i].size() > 1)
            count++;
    }
    return count;
}