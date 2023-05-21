


// #include <iostream>
// #include <vector>
// #include <queue>
// #include "genFunctions.cpp"

void markPath(std::vector<std::vector<std::vector<int>>>& maze, std::queue<std::vector<int>>& order);

void leeAlgorithm(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    std::queue<std::vector<int>> order;
    maze[sr][sc][3] = 1;
    order.push({sr, sc});

    while(!order.empty()){ markPath(maze, order); }

    int min = INT_MAX, nr = er, nc = ec;

    while(er != sr || ec != sc){
        color(maze, er, ec, 'r');
        er = nr;
        ec = nc;

        if(er - 1 > -1 && maze[er - 1][ec][3] && maze[er - 1][ec][3] < min){
            min = maze[er - 1][ec][3];
            nr = er - 1;
            nc = ec;
        }
        if(ec - 1 > -1 && maze[er][ec - 1][3] && maze[er][ec - 1][3] < min){
            min = maze[er][ec - 1][3];
            nr = er;
            nc = ec - 1;
        }
        if(ec + 1 < maze[0].size() && maze[er][ec + 1][3] && maze[er][ec + 1][3] < min){
            min = maze[er][ec + 1][3];
            nr = er;
            nc = ec + 1;
        }
        if(er + 1 < maze.size() && maze[er + 1][ec][3] && maze[er + 1][ec][3] < min){
            min = maze[er + 1][ec][3];
            nr = er + 1;
            nc = ec;
        }

    }
    color(maze, er, ec, 'g');
    return;

}

void markPath(std::vector<std::vector<std::vector<int>>>& maze, std::queue<std::vector<int>>& order){
    int cr = order.front()[0], cc = order.front()[1], i = maze[cr][cc][3] + 1;
    // std::cout << cr << " | " << cc << std::endl;
    color(maze, cr, cc, 'b');
    order.pop();

    if(cr + 1 < maze.size() && clearSpace(maze, cr + 1, cc)){
        maze[cr + 1][cc][3] = i;
        order.push({cr + 1, cc});
    }
    if(cr - 1 > -1 && clearSpace(maze, cr - 1, cc)){
        maze[cr - 1][cc][3] = i;
        order.push({cr - 1, cc});
    }
    if(cc + 1 < maze[0].size() && clearSpace(maze, cr, cc + 1)){
        maze[cr][cc + 1][3] = i;
        order.push({cr, cc + 1});
    }
    if(cc - 1 > - 1 && clearSpace(maze, cr, cc - 1)){
        maze[cr][cc - 1][3] = i;
        order.push({cr, cc - 1});
    }
    return;
}