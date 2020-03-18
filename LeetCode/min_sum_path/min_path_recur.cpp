
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
    
    int helper(vector<vector<int>>& grid, int i, int j)
    {
        if( i == grid.size() || j == grid[0].size() )
        {
           return std::numeric_limits<int>::max();
        }
        
        if( i== grid.size()-1 && j == grid[0].size()-1)
        {
            return grid[i][j];
        }
        
        return grid[i][j] + std::min( helper(grid,i+1,j), helper(grid,i,j+1) );
    }
   
    
    int minPathSum(vector<vector<int>>& grid)
    {
        return helper(grid,0,0);
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