/*

    Basic idea is to just to trace one direction until the goal is met. 
    This assumes that the goal is at the end/border of a maze. 
    This also assumes that there are no cycles i.e. every wall is touching the border by some connection
    A bit unsure about the existence of pits and how to deal with them. 


*/

// #include <iostream>
// #include <vector>
// #include "genFunctions.cpp"

void leftHand(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    int direction = 1;
    while(sr != er || sc != ec){
        // std::cout << sr << " | " << sc << "\tDirection" << direction << std::endl;
        color(maze, sr, sc, 'b');
        switch(direction){
            case 0:
                if(sr - 1 > -1 && clearSpace(maze, sr - 1, sc)){
                    sr--;
                    if(sc - 1 > -1 && clearSpace(maze, sr, sc - 1))
                        direction = 3;
                }
                else
                    direction++;
                break;
            case 1:
                if(sc + 1 < maze[0].size() && clearSpace(maze, sr, sc + 1)){
                    sc++;
                    if(sr - 1 > -1 && clearSpace(maze, sr - 1, sc))
                        direction--;
                }
                else
                    direction++;
                break;
            case 2:
                if(sr + 1 < maze.size() && clearSpace(maze, sr + 1, sc)){
                    sr++;
                    if(sc + 1 < maze[0].size() && clearSpace(maze, sr, sc + 1))
                        direction--;
                }
                else
                    direction++;
                break;
            case 3:
                if(sc - 1 > -1 && clearSpace(maze, sr, sc - 1)){
                    sc--;
                    if(sr - 1 > -1 && clearSpace(maze, sr - 1, sc))
                        direction--;
                }
                else
                    direction = 0;
                break;
            default:
                std::cout << "Error: Invalid direction [wallFollower.cpp]: " << direction << std::endl;
                exit(1); 
        }
    }
    color(maze, sr, sc, 'g');
    return;
}

/*
    I'll have a standard direction and assume opposite if it's filled. 
    i.e. Default is left and down. if the wall is up/down move left, if left is used move right
                                   if the wall is right/left move down, if down is used move up

    Actually with this pattern I may not need the functions below. Could just while through. 
    Move Order: left, if not left then down, if not down then right, if not right then up.
                Could probably loop through these 
    Actually no. Wouldn't hug the wall. Might try this for a separate algorithm though, 

    Maybe I could use numbers and direction to emulate? 
    0 is the top, 1 is the right (their left), 2 is the bottom and 3 is left(their right). 

    Assuming the wall is always to the left move in the direction following the wall. 
    If the wall disappears turn "left" i.e. direction--, if direction < 0 then direction = 3 then move forward;
        -This assumes that the maze is rectangular, thus a missing wall means at least 1 movable space.
        -If I end up testing a non-rectangular maze then I'd just need to make it check the space ahead of time.
        If we've moved forward the previous wall which ended is now to our left, so we repeat the process. 
    If the path ahead is blocked turn "right" i.e. direction++, if direction > 3 then direction = 0
        If we've hit a wall and turned right, the wall we hit is now to our left, so we repeat the process.

    So this process deals with 3 states. 
        1] the wall is to the left ahead
        2] the wall ends ahead
        3] we'll strike a new wall ahead. 

    So check if space is in array
        If not, turn right.
    If it is check if it's open
        If not, turn right
    If it is check if the space left to it is open
        If not move forward
    If it is move forward and turn left
    
*/ 
// int wallIsUp(){};
// int wallIsDown(){};
// int wallIsLeft(){};
// int wallIsRight(){};