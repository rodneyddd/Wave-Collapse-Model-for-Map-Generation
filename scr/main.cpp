#include <iostream>
#include "Map/Map.hpp"
#include <vector>
#include <time.h>

using namespace std;

int main(){

    time_t begin, end;
    

    vector<int> state = {1,2,3,4,5};

    Map map(10, 10, state);

    time(&begin);
    map.wave_collapse();
    time(&end);

    time_t elapsed = end - begin;

    cout << elapsed << "  seconds" << endl;
    
    
    map.save_map();
  
    return 0;
}