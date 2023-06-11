#include "Node.hpp"


Node::Node(){
    North = nullptr;
    North_East = nullptr;
    East = nullptr;
    South_East = nullptr;
    South = nullptr;
    South_West = nullptr;
    West = nullptr;
    North_West = nullptr;

    state = {}; 
    anti_state = {};
}

void Node::setSurrondingNodes(){
    sur_Node = new Node *[8];
    
    sur_Node[0] = North; 
    sur_Node[1] = North_East; 
    sur_Node[2] = East; 
    sur_Node[3] = South_East; 
    sur_Node[4] = South; 
    sur_Node[5] = South_West; 
    sur_Node[6] = West; 
    sur_Node[7] = North_West;
}

void Node::setState(vector<int> value){
    
    state.clear();
    stateSize = value.size();
    for(int i = 0; i < value.size(); i++)
      state.push_back(value[i]);
    
}

void Node::setAntiState(vector<int> value){
    
    anti_state.clear();

    for(int i = 0; i < value.size(); i++)
        anti_state.push_back(value[i]);
}

void Node::setAdamState( map<int , vector<vector<int>> > adam_state){
    this->adam_state = adam_state;
}

bool Node::removeState(vector<int> value){
    bool check_state = false;

    for(int i = 0; i < value.size(); i++){
        for(int j = 0; j < state.size(); j++){
            if(state[j] == value[i]){
                state.erase(state.begin() + j);
                check_state = true;
            }
        }
    }

    return check_state;
}

vector<int> Node::getState(){
    return state;
}

vector<int> Node::getAntiState(){
    return anti_state;
}

void Node::displayState(){
    cout << "{ ";
    for(int i = 0; i < state.size(); i++){
        cout << state[i] << " ";
    }
    cout << "}";
}

void Node::displayAntiState(){
    cout << "{ ";
    for(int i = 0; i < anti_state.size(); i++){
        cout << anti_state[i] << " ";
    }
    cout << "}";
}

int Node::getStateSize(){
    return state.size();
}

void Node::updateState(Node* node){
    vector<int> state = node->getState();
    vector<int> new_state;
    
    for(int i = 0; i < state.size(); i++){
        for(int j = 0; j < adam_state[state[i]][0].size(); j++){
            
            if (!(count(new_state.begin(), new_state.end(), adam_state[state[i]][0][j]))) {
                new_state.push_back(adam_state[state[i]][0][j]);
            }
           
        } 
    }

    vector<int> anti_state;

    for(int i = 0; i < adam_state[0][0].size(); i++){

        if (!(count(new_state.begin(), new_state.end(), adam_state[0][0][i]))) {
            anti_state.push_back(adam_state[0][0][i]);
        }
    }

    node->setAntiState(anti_state);
}

bool Node::checkState(){
    bool check;
   
    for(int k = 0; k < 8; k++){
        if(sur_Node[k] != nullptr){
            if(anti_state.size() != 0)
                check = sur_Node[k]->removeState(anti_state);
            if(check)
                sur_Node[k]->updateState(sur_Node[k]);
        }
    }
    

    return check;
}


// adam_state.insert(pair<int , vector<vector<int>> >(0, {{1,2,3,4,5}, {}}));
// adam_state.insert(pair<int , vector<vector<int>> >(1, {{1,2},       {3,4,5}}));
// adam_state.insert(pair<int , vector<vector<int>> >(2, {{1,2,3},     {4,5}}));
// adam_state.insert(pair<int , vector<vector<int>> >(3, {{2,3,4},     {1,5}}));
// adam_state.insert(pair<int , vector<vector<int>> >(4, {{3,4,5},     {1,2}}));
// adam_state.insert(pair<int , vector<vector<int>> >(5, {{4,5},       {1,2,3}}));
