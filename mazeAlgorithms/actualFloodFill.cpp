


// Just trying it out for fun. Curious what it would look like.
// #include <iostream>
// #include <vector>
// #include <queue>
// #include "genFunctions.cpp"

bool flooder(std::vector<std::vector<std::vector<int>>>& maze, std::queue<std::pair<int, int>>& levelQueue, int sr, int sc, int er, int ec);

void actualFloodFill(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    std::queue<std::pair<int, int>> levelQueue;
    levelQueue.push({sr, sc});
    bool goal = false;
    while(!levelQueue.empty()){
        if(goal)
            break;
        if(!clearSpace(maze, levelQueue.front().first, levelQueue.front().second)){
            levelQueue.pop();
            continue;
        }
        goal = flooder(maze, levelQueue, levelQueue.front().first, levelQueue.front().second, er, ec);
        levelQueue.pop();
    }
    return;
}

bool flooder(std::vector<std::vector<std::vector<int>>>& maze, std::queue<std::pair<int, int>>& levelQueue, int sr, int sc, int er, int ec){
    // std::cout << sr << " | " << sc << std::endl;
    if(sr == er && sc == ec){
        color(maze, sr, sc, 'g');
        return true;
    }
    maze[sr][sc][3] = 1;
    color(maze, sr, sc, 'b');
    if(sr - 1 > -1 && clearSpace(maze, sr - 1, sc))
        levelQueue.push({sr - 1, sc});
    bool found = false;
    if(sr + 1 < maze.size() && clearSpace(maze, sr + 1, sc))
        found = flooder(maze, levelQueue, sr + 1, sc, er, ec);
    if(!found && sc + 1 < maze[0].size() && clearSpace(maze, sr, sc + 1))
        found = flooder(maze, levelQueue, sr, sc + 1, er, ec);
    if(!found && sc - 1 > -1 && clearSpace(maze, sr, sc - 1))
        found = flooder(maze, levelQueue, sr , sc - 1, er, ec);
    if(found)
        return true;
    return false;
}