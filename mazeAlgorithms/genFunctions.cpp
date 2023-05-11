


#include <iostream>
#include <vector>

void color(std::vector<std::vector<std::vector<int>>>& maze, int cr, int cc, char c){
    if(c == 'r'){
        maze[cr][cc][0] = 255;
        maze[cr][cc][1] = 70;
        maze[cr][cc][2] = 70;
    }
    if(c == 'g'){
        maze[cr][cc][0] = 70;
        maze[cr][cc][1] = 255;
        maze[cr][cc][2] = 70;
    }
    else{
        maze[cr][cc][0] = 70;
        maze[cr][cc][1] = 70;
        maze[cr][cc][2] = 255;
    }
};