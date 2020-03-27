/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <limits>
#include <tuple>

using namespace std;
int inf = 2147483647;

class Solution {

private:

    int inf = 2147483647;
    int motion_x[4] = {0,0,-1,1};
    int motion_y[4] = {1,-1,0,0};

public:
    
    void bfs(vector<vector<int>>& rooms, int i, int j, int dist)
    {
        queue<tuple<int,int,int>> q;
        q.push(std::make_tuple(i,j,dist));
        int curr_i, curr_j,d=0;
        
        while(!q.empty())
        {
            std::tuple temp = q.front();
            curr_i = std::get<0>(temp);
            curr_j = std::get<1>(temp);
            d = std::get<2>(temp);
            q.pop();
            // cout<<"i= "<<curr_i<<", j= "<<curr_j<<endl;
            
            for(int i = 0; i < 4; i++)
            {
                int r = curr_i + motion_x[i];
                int c = curr_j + motion_y[i];
                if(r < 0 || c < 0 || r >= rooms.size() || c >= rooms[0].size()) continue;
                if(rooms[r][c] != inf && rooms[r][c] < rooms[curr_i][curr_j]+1) continue;
                rooms[r][c] = rooms[curr_i][curr_j]+1;     
                q.push(std::make_tuple(r, c, d+1));
                // cout<<"inf new val = "<< d+1<<endl;
            }
        }
        
        
    }
    
    void wallsAndGates(vector<vector<int>>& rooms)
    {
        for(std::size_t i = 0; i < rooms.size(); i++)
        {
            for(std::size_t j = 0; j < rooms[i].size(); j++)
            {
                if(rooms[i][j] == 0)
                {
                    bfs(rooms, i, j,0);
                }
            }
        }
    }
};

int main()
{
    int inf = 2147483647;
    std::vector<vector<int>> grid;
    std::vector<int> elem;
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    elem = {inf,-1,0,inf};
    grid.push_back(elem);
    elem = {inf,inf,inf,-1};
    grid.push_back(elem);
    elem = {inf,-1,inf,-1};
    grid.push_back(elem);
    elem = {0,-1,inf,inf};
    grid.push_back(elem);

    Solution s;
    s.wallsAndGates(grid);

    for(std::size_t i = 0; i<grid.size(); i++)
        {
            std::cout<<"[";
            for(std::size_t j = 0; j<grid[0].size(); j++)
            {
                std::cout<<grid[i][j]<<",";
            }
            std::cout<<"],"<<std::endl;
        }
    return 0;
}