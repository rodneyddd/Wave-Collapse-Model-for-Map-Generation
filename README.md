# Wave Collapse Map Generations 🗺

I wanted to start this project because I was fascinated by computers executing random jobs for humanity. The fundamental idea is to give the computer a 2D map and it will produce a random tile arrangement. The project is primarily concerned with Object-Oriented Programming (OOP), pointers, and C++.

Step 1: Completed C++
I finished the C++ section of the project after putting in considerable effort. I had to take a break and rethink my strategy at one point because my previous method proved to be too intricate. As a result, I simplified my approach. The project is centered on two classes: "Node" and "Map."

### Node
The Node class represents a node that is linked to other nodes using coordinates. It also contains a master node known as "sur_Node," which connects to the other eight nodes. Every node has a state as well as an anti-state. The state specifies the possible values for a node, but the anti-state specifies what it cannot be. Furthermore, the Node class includes a number of assistance functions, such as standard getters and setters for private characteristics such as the node state and anti-state.

</br>

```
   public:
        Node* North;
        Node* North_East;
        Node* East;
        
        Node* West;
        Node* North_West;

        Node** sur_Node;
```

The only difference between my initial approach and this one is that I added two additional functions: *checkState()* and *updateState(Node* node)*. Checkstate is used to update the sur_Nodes states based on the current node's change. For example, if the node became a 3, the surrond state should be a 2,3,4 and their anti_states should be a 1,5. 
The difference in this approach is that I tried to map change the sur_node state, but it is much easier to do it locally.
</br>

### Map
  The map obj was where I had some issues. I create a constructor to make a 2d array based on a user input for size but I was creating the pointer incorrectly.</br>
  ```
  obj*  arr  = new obj[10]   👎 ❌ 
  obj** arr = new obj*[10]   👍 ✔
  ```
  The map is significantly simpler because the majority of the hard activities, notably the updating of the surrounding nodes, are done within the node class. The major responsibility of the map is to generate the 2D map and start the wave collapse. The wave collapse method is now contained within a while loop. The wave starts when a position is chosen and spreads to surrounding nodes based on that change.
  
</br>

```
   [{1,2,3} {1,2,3} {1,2,3}]                          [{1,2,3} {1,2,3} {1,2,3}]
   [{1,2,3} {1,2,3} {1,2,3}]                          [{2,3}    {2,3}    {2,3}]  
   [{1,2,3} {1,2,3} {1,2,3}]                          [{2,3}     {3}     {2,3}]  
   [{1,2,3} {1,2,3} {1,2,3}]                          [{2,3}    {2,3}    {2,3}]  
   [{1,2,3} {1,2,3} {1,2,3}]                          [{1,2,3} {1,2,3} {1,2,3}]
   
```

</br>
</br>
</hr>

### Example 
  This is an example of a generated map. It was generated with 50 x 50 nodes (2500 nodes) and the pixels imgs was added with python. The rules are set as below;
<div style = "width: 100%;">
  <img src= "./scr_python/data/1.png" style = "display: inline-block; padding: 20px;"/>

  <img src= "./scr_python/data/2.png" style = "display: inline-block; padding: 20px;"/>

  <img src= "./scr_python/data/3.png" style = "display: inline-block; padding: 20px;"/>

  <img src= "./scr_python/data/4.png" style = "display: inline-block; padding: 20px;"/>

  <img src= "./scr_python/data/5.png" style = "display: inline-block; padding: 20px;"/>
</div>

<img src = "./scr_python/data/50x50.jpg"/>

<img src = "./scr_python/data/test100.jpg"/>

# Where to next
- html css and java.
