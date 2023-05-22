


// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <queue>
// #include "genFunctions.cpp"

void aStarAdjacent(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    std::priority_queue<std::pair<int, std::vector<int>>> order;
    int ssr = sr, ssc = sc;
    maze[sr][sc][4] = -1;
    maze[sr][sc][5] = -1;
    order.push({0, {sr, sc}});

    while(!order.empty()){
        sr = order.top().second[0], sc = order.top().second[1];
        // std::cout << sr << " | " << sc << " || " << maze[sr][sc][3] << std::endl;
        // std::cout << maze[sr][sc][3] << " | " << maze[sr][sc][3] + 1 << std::endl;
        color(maze, sr, sc, 'b');
        order.pop();

        if(sr == er && sc == ec)
            break;
        
        if(sr + 1 < maze.size() && (clearSpace(maze, sr + 1, sc) || (maze[sr + 1][sc][3] && maze[sr + 1][sc][3] > maze[sr][sc][3] + 1))){
            order.push({INT_MAX - (abs((sr + 1) - er) + abs(sc - ec)), {sr + 1, sc}});
            maze[sr + 1][sc][3] = maze[sr][sc][3] + 1;
            maze[sr + 1][sc][4] = sr;
            maze[sr + 1][sc][5] = sc;
        }
        if(sc + 1 < maze[0].size() && (clearSpace(maze, sr, sc + 1) || (maze[sr][sc + 1][3] && maze[sr][sc + 1][3] > maze[sr][sc][3] + 1))){
            order.push({INT_MAX - (abs(sr - er) + abs((sc + 1) - ec)), {sr, sc + 1}});
            maze[sr][sc + 1][3] = maze[sr][sc][3] + 1;
            maze[sr][sc + 1][4] = sr;
            maze[sr][sc + 1][5] = sc;
        }
        if(sc - 1 > -1 && (clearSpace(maze, sr, sc - 1) || (maze[sr][sc - 1][3] && maze[sr][sc - 1][3] > maze[sr][sc][3] + 1))){
            order.push({INT_MAX - (abs(sr - er) + abs((sc - 1) - ec)), {sr, sc - 1}});
            maze[sr][sc - 1][3] = maze[sr][sc][3] + 1;
            maze[sr][sc - 1][4] = sr;
            maze[sr][sc - 1][5] = sc;
        }
        if(sr - 1 > -1 && (clearSpace(maze, sr - 1, sc) || (maze[sr - 1][sc][3] && maze[sr - 1][sc][3] > maze[sr][sc][3] + 1))){
            order.push({INT_MAX - (abs((sr - 1) - er) + abs(sc - ec)), {sr - 1, sc}});
            maze[sr - 1][sc][3] = maze[sr][sc][3] + 1;
            maze[sr - 1][sc][4] = sr;
            maze[sr - 1][sc][5] = sc;
        }
    }

    // std::cout << sr << " here " << sc << std::endl;
    color(maze, sr, sc, 'g');
    maze[ssr][ssc][4] = -1;
    maze[ssr][ssc][5] = -1;
    
    int tr = sr;
    sr = maze[sr][sc][4];
    sc = maze[tr][sc][5];
    while(sr != -1 && sc != -1){
        color(maze, sr, sc, 'r');
        tr = sr;
        sr = maze[sr][sc][4];
        sc = maze[tr][sc][5];
    }
    return;
}