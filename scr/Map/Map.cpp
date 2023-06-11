#include "Map.hpp"

Map::Map(int row, int col, vector<int> state){
    int k = 0;
    arr = new Node*[row];
    this->row = row;
    this->col = col;

    adam_state.insert(pair<int , vector<vector<int>> >(0, {{1,2,3,4,5}, {}}));
    adam_state.insert(pair<int , vector<vector<int>> >(1, {{1,2},   {3,4,5}}));
    adam_state.insert(pair<int , vector<vector<int>> >(2, {{1,2,3}, {4,5}}));
    adam_state.insert(pair<int , vector<vector<int>> >(3, {{2,3,4}, {1,5}}));
    adam_state.insert(pair<int , vector<vector<int>> >(4, {{3,4,5},   {1,2}}));
    adam_state.insert(pair<int , vector<vector<int>> >(5, {{4,5}, {1,2,3}}));

    for(int i = 0; i < row; i++){
        arr[i] = new Node[col];
    }

    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            tracker.push_back(k);
            if(-1 < (i-1) and (i-1) < row)
                arr[i][j].North        = &arr[i-1][j]; 

            if(-1 < (i-1) and (i-1) < row and -1 < (j+1) and (j+1) < col)
                arr[i][j].North_East   = &arr[i-1][j+1];    

            if( -1 < (j+1) and (j+1) < col)
                arr[i][j].East         = &arr[i][j+1];

            if(-1 < (i+1) and (i+1) < row and -1 < (j+1) and (j+1) < col)
                arr[i][j].South_East   = &arr[i+1][j+1];

            if(-1 < (i+1) and (i+1) < row)
                arr[i][j].South        = &arr[i+1][j]; 

            if(-1 < (i+1) and (i+1) < row and -1 < (j-1) and (j-1) < col)
                arr[i][j].South_West   = &arr[i+1][j-1];  

            if( -1 < (j-1) and (j-1) < col)
                arr[i][j].West         = &arr[i][j-1];

            if(-1 < (i-1) and (i-1) < row and -1 < (j-1) and (j-1) < col)
                arr[i][j].North_West   = &arr[i-1][j-1];     

            arr[i][j].setState(state);
            arr[i][j].setSurrondingNodes();
            arr[i][j].setAdamState(adam_state);
            k++;
        }

    }

   
}

bool Map::collapsed(){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j].getStateSize() != 1)
                return false;
        }
    }

    return true;
}

void Map::wave_collapse(){
    
    vector<int> state;
    vector<int> anti_state;

    bool wave = true;
    bool check = false;

    int size = adam_state[0][0].size();

    int rand_state;
    int rand_row;
    int rand_col;
    int rand_pos;
    
    int row_beg;
    int col_beg;
    int row_end;
    int col_end;

    srand((unsigned int)time(NULL));

    while(tracker.size() != 0){    
        
        rand_pos = rand() % tracker.size();

        rand_row = floor(tracker[rand_pos]/row);
        rand_col = tracker[rand_pos]%col;
       
        system("clear");
        cout << tracker.size() << endl;
       
        tracker.erase(tracker.begin() + rand_pos);

        
        state = arr[rand_row][rand_col].getState();
        rand_state = rand() % state.size(); 

        anti_state = adam_state[state[rand_state]][1];

        arr[rand_row][rand_col].setState({state[rand_state]});
        arr[rand_row][rand_col].setAntiState(anti_state);
        arr[rand_row][rand_col].checkState();
         
        

        while(wave){
            wave = false;

            for(int i = rand_row-6 ; i < rand_row+6; i++){
                for(int j = rand_col-6; j < rand_col+6; j++){
                        if (( 0 <= i and i < row) and (0 <= j and j < col)){
                           check = arr[i][j].checkState();
                        }
                        else{
                          
                            row_beg = i;
                            col_beg = j;

                            if(i < 0)
                                row_beg = 0;
                            else if( i >= row)
                                row_beg = row-1;
                            
                            
                            if(j < 0)
                                col_beg = 0;
                            else if(j >= col)
                                col_beg = col-1;
                           

                            check = arr[row_beg][col_beg].checkState();
                        }
                            
                               
                        
                        if(check)
                            wave = check;
                    }
                }
            }
                // if(! (rand_row - adam_state[0][0].size()-1) < 0)
                //     row_beg = rand_row-adam_state[0][0].size() -1;
                // else
                //     row_beg = 0;

                // if(!(rand_col - adam_state[0][0].size()-1) < 0)
                //     col_beg = rand_col - adam_state[0][0].size() -1;
                // else    
                //     col_beg = 0;

                // if(!(rand_row+adam_state[0][0].size()+1) > row)
                //     row_end = rand_row + adam_state[0][0].size() +1;
                // else
                //     row_end = row;

                // if(!(rand_col+adam_state[0][0].size()+1) > col)
                //     col_end = rand_col + adam_state[0][0].size() +1;
                // else
                //     col_end = col;

                // for(int i = row_beg ;i < row_end; i++){
                //     for(int j = col_beg; j < col_end; j++){
                //         check = arr[i][j].checkState();
                //         if(check)
                //             wave = check;
                //     }
                // }

                // for(int i = 0; i < row; i++){
                //     for(int j = 0; j < col; j++){
                //         check = arr[i][j].checkState();
                //         if(check)
                //             wave = check;
                //     }
                // }
        //}

        wave = true;
        check = false;
    }

}

void Map::displayMap(){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j].displayState();
            cout  << " | ";
        }

        cout << endl;
    }
}

void Map::displayAntiMap(){

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j].displayAntiState();
            cout  << " | ";
        }

        cout << endl;
    }
}

void Map::save_map(){
    ofstream File("../scr_python/data/wave_collapse.txt");
    vector<int> state;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            state = arr[i][j].getState();

            for(int k = 0; k < 1; k++){
                File << state[0] << "  ";
            }
            
        }
        File << endl;
    }
}