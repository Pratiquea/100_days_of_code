/*
Question


Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <limits>
#include <set>

using namespace std;

class Solution {
public:
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int columns = grid[0].size();
        int int_max = std::numeric_limits<int>::max();
        std::vector<vector<int>> dp(rows,std::vector<int>(columns));
        
        for(std::size_t i = 0; i<rows ; i++)
        {
            for(std::size_t j = 0; j <columns; j++)
            {
                if(i == 0 && j != 0)
                { dp[i][j] = grid[i][j] + dp[i][j-1] ; }
                else if(i != 0 && j == 0)
                { dp[i][j] = grid[i][j] + dp[i-1][j] ; }
                else if(i != rows && j != columns && i!=0 && j!=0)
                { dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]); }
                else
                { dp[i][j] = grid[i][j]; }
                
            }
        }
        
        return dp[rows-1][columns-1];       
    }  
};

int main()
{
    std::vector<vector<int>> grid;
    std::vector<int> elem;
    elem = {1,3,1};
    grid.push_back(elem);
    elem = {1,5,1};
    grid.push_back(elem);
    elem = {4,2,1};
    grid.push_back(elem);


    Solution s;
    int sum = s.minPathSum(grid);
    std::cout<<"sum = "<< sum <<std::endl;

    // fo`r(std::size_t i = 0; i<grid.size(); i++)
    //     {
    //         std::cout<<"[";
    //         for(std::size_t j = 0; j<grid[0].size(); j++)
    //         {
    //             std::cout<<grid[i][j]<<",";
    //         }
    //         std::cout<<"],"<<std::endl;
    //     }
    return 0;
}