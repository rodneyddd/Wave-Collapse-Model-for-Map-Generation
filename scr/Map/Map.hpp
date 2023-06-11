#ifndef MAP_H
#define MAP_H

#include "../Node/Node.hpp"
#include <map>
#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class Map{
    public:
        Map(int row, int col, vector<int> state);
        
        bool collapsed();
        void wave_collapse();
        void displayMap();
        void displayAntiMap();

        void save_map();

    private:
        map<int , vector<vector<int>> > adam_state;
        map<int , vector<vector<int>> >::iterator itr;
  
        Node** arr;

        vector<int> tracker;
        int row;
        int col;
};


#endif