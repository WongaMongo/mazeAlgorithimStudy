/*
    Starting with Flood fill since it's uninformed.

    Flood fill essentially brute forces itself into a solution by recursively running itself on adjacent open squares. 
    If flood fill is called on a used square it cancels itself to avoid redundancy. 
    Could either run with stack or a queue, might do both later on to see which runs better. 
    I'll try just plain recursion for now. Should be similar to queue. 
    
    For the successful path I'll probably color it blue and the other paths red. 
    Which means floodfill has to return something. Probably a bool. 
    If foundEnd = true, recolor the function location blue. Else return. 

    So the pseudocode I'm thinking so far:
        Mark end point [endheight][endwidth]
        Run Floodfill on starting point [height][width]
        
        bool Floodfill(height, width)
            if(wall or colored/occupied)
                return false;
            colorPixel(red);
            bool found = false;
            found += Floodfill(up);
            if(!found)
                found += Floodfill(down);
            if(!found)
                found += Floodfill(left);
            if(!found)
                found += Floodfill(right);
            if(found){
                colorPixel(blue);
                return true;
            }
            return false;

        return changedImg;

*/

#include <iostream>
#include <vector>
#include "genFunctions.cpp"

// Using a recursive bool function to emulate a stack's lifo
bool floodFillAlgorithm(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    if(sr == er && sc == ec){
        color(maze, sr, sc, 'g');
    }
    if(maze[sr][sc][3] || maze[sr][sc][0] < 127 && maze[sr][sc][1] < 127 && maze[sr][sc][2] < 127)
        return false;
    maze[sr][sc][3] = 1;
    color(maze, sr, sc, 'r');
    bool route = false;
    if(sr + 1 < maze.size())
        route += floodFillAlgorithm(maze, sr + 1, sc, er, ec);
    if(!route && sr - 1 > -1)
        route += floodFillAlgorithm(maze, sr - 1, sc, er, ec);
    if(!route && sc + 1 < maze[0].size())
        route += floodFillAlgorithm(maze, sr, sc + 1, er, ec);
    if(!route && sc - 1 > -1)
        route += floodFillAlgorithm(maze, sr, sc - 1, er, ec);
    if(route){
        color(maze, sr, sc, 'b');
        return true;
    }
    return false;
};