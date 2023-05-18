


// #include <iostream>
// #include <vector>
// #include <stack>
// #include "genFunctions.cpp"

void depthFirstSearch(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    std::stack<std::pair<int, int>> trail;
    maze[sr][sc][4] = -1;
    maze[sr][sc][5] = -1;
    trail.push({sr, sc});
    
    while(!trail.empty()){
        sr = trail.top().first;
        sc = trail.top().second;
        trail.pop();
        maze[sr][sc][3] = 1;

        if(sr == er && sc == ec)
            break;
        color(maze, sr, sc, 'b');

        if(sr - 1 > -1 && clearSpace(maze, sr - 1, sc)){
            maze[sr - 1][sc][4] = sr;
            maze[sr - 1][sc][5] = sc;
            trail.push({sr - 1, sc});
        }
        if(sc - 1 > -1 && clearSpace(maze, sr, sc - 1)){
            maze[sr][sc - 1][4] = sr;
            maze[sr][sc - 1][5] = sc;
            trail.push({sr, sc - 1});
        }
        if(sc + 1 < maze[0].size() && clearSpace(maze, sr, sc + 1)){
            maze[sr][sc + 1][4] = sr;
            maze[sr][sc + 1][5] = sc;
            trail.push({sr, sc + 1});
        }
        if(sr + 1 < maze.size() && clearSpace(maze, sr + 1, sc)){
            maze[sr + 1][sc][4] = sr;
            maze[sr + 1][sc][5] = sc;
            trail.push({sr + 1, sc});
        }
    }
    
    color(maze, sr, sc, 'g');
    int tr;
    tr = sr;
    sr = maze[sr][sc][4];
    sc = maze[sr][sc][5];
    
    while(sr != -1 && sc != -1){
        color(maze, sr, sc, 'r');
        tr = sr;
        sr = maze[sr][sc][4];
        sc = maze[tr][sc][5];
    }

    return;
}