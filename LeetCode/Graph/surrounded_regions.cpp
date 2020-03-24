/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
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
    
    void captureBorderCases(vector<vector<char>>& board, int i, int j)
    {
        if(i< 0 || j < 0 || i>=board.size() || j>=board[0].size()) return;
        
        if(board[i][j] == 'X') return;
        
        board[i][j] = 'X';
        captureBorderCases(board,i-1,j);
        captureBorderCases(board,i+1,j);
        captureBorderCases(board,i,j-1);
        captureBorderCases(board,i,j+1);
    }
    
    vector<vector<char>> xorComplement(vector<vector<char>>& src,vector<vector<char>>& dst)
    {
        for(std::size_t i = 0; i<dst.size(); i++)
        {
            for(std::size_t j=0; j<dst[0].size(); j++)
            {
                if(src[i][j] == 'X' && dst[i][j] =='X')
                    dst[i][j] = 'X';
                else if(src[i][j] == 'X' && dst[i][j] =='O')
                    dst[i][j] = 'O';
                else if(src[i][j] == 'O' && dst[i][j] =='X')
                    dst[i][j] = 'O';
                else if(src[i][j] == 'O' && dst[i][j] =='O')
                    dst[i][j] = 'X';
            }
        }
        
        return dst;
    }
    
    void solve(vector<vector<char>>& board)
    {
        auto grid = board;
        
        for(std::size_t i = 0; i<board.size(); i++)
        {
            for(std::size_t j=0; j<board[0].size(); j++)
            {
                if(i == 0 || j == 0 || i==board.size()-1 || j==board[0].size()-1)
                {
                    captureBorderCases(board,i,j);
                }
            }
        }
        
        board = xorComplement(grid,board);
    }
};

int main()
{
    std::vector<vector<char>> grid;
    std::vector<char> elem;
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    elem = {'X','X','X','X','X','X'};
    grid.push_back(elem);
    elem = {'X','O','O','O','X','X'};
    grid.push_back(elem);
    elem = {'X','X','O','O','X','X'};
    grid.push_back(elem);
    elem = {'X','O','O','X','O','X'};
    grid.push_back(elem);
    elem = {'X','X','X','X','O','X'};
    grid.push_back(elem);
    elem = {'X','O','O','O','O','X'};
    grid.push_back(elem);
// [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

    for(std::size_t i = 0; i<grid.size(); i++)
        {
            std::cout<<"[";
            for(std::size_t j = 0; j<grid[0].size(); j++)
            {
                std::cout<<grid[i][j]<<",";
            }
            std::cout<<"],"<<std::endl;
        }
        std::cout<<std::endl;

    Solution s;
    s.solve(grid);

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