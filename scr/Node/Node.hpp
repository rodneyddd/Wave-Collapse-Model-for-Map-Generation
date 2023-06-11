#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <algorithm>  
#include <vector>
#include <map>
using namespace std;

class Node {
    public:
        Node* North;
        Node* North_East;
        Node* East;
        Node* South_East;
        Node* South;
        Node* South_West;
        Node* West;
        Node* North_West;

        Node** sur_Node;
        
        Node();

        void setState(vector<int> value);
        void setAntiState(vector<int> value);
        void setAdamState( map<int , vector<vector<int>> > adam_state);

        bool removeState(vector<int> value);
        void compareState(vector<int> value);

        void setSurrondingNodes();

        vector<int> getState();
        vector<int> getAntiState();

        void updateState(Node* node);
        void displayState();
        void displayAntiState();
        int  getStateSize();

        bool checkState();

        friend std::ostream&  operator<<(std::ostream& os, const Node& node);    

    private:
        map<int , vector<vector<int>> > adam_state;
        vector<int> state; 
        vector<int> anti_state;
        int  stateSize;
};




#endif