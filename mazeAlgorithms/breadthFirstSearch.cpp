


// #include <iostream>
// #include <vector>
// #include <queue>
// #include "genFunctions.cpp"

void breadthFirstSearch(std::vector<std::vector<std::vector<int>>>& maze, int sr, int sc, int er, int ec){
    std::queue<std::pair<int, int>> depth;
    maze[sr][sc][3] =  1;
    maze[sr][sc][4] = -1;
    maze[sr][sc][5] = -1;
    depth.push({sr, sc});
    int cr = 0, cc = 0, tr = 0, cost = 0;
    while(!depth.empty()){
        cr = depth.front().first;
        cc = depth.front().second;
        depth.pop();

        // std::cout << cr << " | " << cc << " | " << cost << std::endl;

        if(cr == er && cc == ec)
            break;

        color(maze, cr, cc, 'b');

        if(cr + 1 < maze.size() && !maze[cr + 1][cc][3] && clearSpace(maze, cr + 1, cc)){
            maze[cr + 1][cc][3] = 1;
            maze[cr + 1][cc][4] = cr;
            maze[cr + 1][cc][5] = cc;
            depth.push({cr + 1, cc});
        }
        if(cr - 1 > -1 && !maze[cr - 1][cc][3] && clearSpace(maze, cr - 1, cc)){
            maze[cr - 1][cc][3] = 1;
            maze[cr - 1][cc][4] = cr;
            maze[cr - 1][cc][5] = cc;
            depth.push({cr - 1, cc});
        }
        if(cc + 1 < maze[0].size() && !maze[cr][cc + 1][3] && clearSpace(maze, cr, cc + 1)){
            maze[cr][cc + 1][3] = 1;
            maze[cr][cc + 1][4] = cr;
            maze[cr][cc + 1][5] = cc;
            depth.push({cr, cc + 1});
        }
        if(cc - 1 > -1 && !maze[cr][cc - 1][3] && clearSpace(maze, cr, cc - 1)){
            maze[cr][cc - 1][3] = 1;
            maze[cr][cc - 1][4] = cr;
            maze[cr][cc - 1][5] = cc;
            depth.push({cr, cc - 1});
        }
    }

    color(maze, cr, cc, 'g');
    tr = cr;
    cr = maze[cr][cc][4];
    cc = maze[tr][cc][5];
    while(cr != -1 && cc != -1){
        color(maze, cr, cc, 'r');
        tr = cr;
        cr = maze[cr][cc][4];
        cc = maze[tr][cc][5];
    }
    return;
}



        // if(cr + 1 < maze.size() && !maze[cr + 1][cc][3]){
        //     maze[cr + 1][cc][3] = 1;
        //     maze[cr + 1][cc][4] = cr;
        //     maze[cr + 1][cc][5] = cc;
        //     depth.push({cr + 1, cc});
        // }
        // if(cr - 1 > -1 && !maze[cr - 1][cc][3]){
        //     maze[cr - 1][cc][3] = 1;
        //     maze[cr - 1][cc][4] = cr;
        //     maze[cr - 1][cc][5] = cc;
        //     depth.push({cr - 1, cc});
        // }
        // if(cc + 1 < maze[0].size() && !maze[cr][cc + 1][3]){
        //     maze[cr][cc + 1][3] = 1;
        //     maze[cr][cc + 1][4] = cr;
        //     maze[cr][cc + 1][5] = cc;
        //     depth.push({cr, cc + 1});
        // }
        // if(cc - 1 > -1 && !maze[cr][cc - 1][3]){
        //     maze[cr][cc - 1][3] = 1;
        //     maze[cr][cc - 1][4] = cr;
        //     maze[cr][cc - 1][5] = cc;
        //     depth.push({cr, cc - 1});
        // }

        // if(cr + 1 < maze.size() && maze[cr + 1][cc][3] < cost - 1 && clearSpace(maze, cr + 1, cc)){
        //     maze[cr + 1][cc][3] = cost - 1;
        //     maze[cr + 1][cc][4] = cr;
        //     maze[cr + 1][cc][5] = cc;
        //     depth.push({cr + 1, cc, cost - 1});
        // }
        // if(cr - 1 > -1 && maze[cr - 1][cc][3] < cost - 1 && clearSpace(maze, cr - 1, cc)){
        //     maze[cr - 1][cc][3] = cost - 1;
        //     maze[cr - 1][cc][4] = cr;
        //     maze[cr - 1][cc][5] = cc;
        //     depth.push({cr - 1, cc, cost - 1});
        // }
        // if(cc + 1 < maze[0].size() && maze[cr][cc + 1][3] < cost - 1 && clearSpace(maze, cr, cc + 1)){
        //     maze[cr][cc + 1][3] = cost - 1;
        //     maze[cr][cc + 1][4] = cr;
        //     maze[cr][cc + 1][5] = cc;
        //     depth.push({cr, cc + 1, cost - 1});
        // }
        // if(cc - 1 > -1 && maze[cr][cc - 1][3] < cost - 1 && clearSpace(maze, cr, cc - 1)){
        //     maze[cr][cc - 1][3] = cost - 1;
        //     maze[cr][cc - 1][4] = cr;
        //     maze[cr][cc - 1][5] = cc;
        //     depth.push({cr, cc - 1, cost - 1});
        // }