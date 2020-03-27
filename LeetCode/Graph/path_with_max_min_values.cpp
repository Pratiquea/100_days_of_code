/*
Given a matrix of integers A with R rows and C columns, find the maximum score of a path starting at [0,0] and ending at [R-1,C-1].

The score of a path is the minimum value in that path.  For example, the value of the path 8 →  4 →  5 →  9 is 4.

A path moves some number of times from one visited cell to any neighbouring unvisited cell in one of the 4 cardinal directions (north, east, west, south).

 

Example 1:



Input: [[5,4,5],[1,2,6],[7,4,6]]
Output: 4
Explanation: 
The path with the maximum score is highlighted in yellow. 
Example 2:



Input: [[2,2,1,2,2,2],[1,2,2,2,1,2]]
Output: 2
Example 3:



Input: [[3,4,6,3,4],[0,2,1,1,7],[8,8,3,2,7],[3,2,4,9,8],[4,1,2,0,0],[4,6,5,4,3]]
Output: 3
 

Note:

1 <= R, C <= 100
0 <= A[i][j] <= 10^9

*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <limits>
#include <tuple>

using namespace std;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        static constexpr int direction[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int m = A.size(), n = A[0].size();

        priority_queue<tuple<int,int,int>> pq;
        pq.emplace(A[0][0], 0, 0);
        int maxScore = A[0][0];
        A[0][0] = -1;

        while(!pq.empty())
        {
            auto [val, i, j] = pq.top();
            pq.pop();
            maxScore = min(maxScore,val);

            if(i == m-1 && j == n-1) break;
            for(const auto& d:direction)
            {
                int r=i+d[0], c=j+d[1];
                if(r>=0 && c>=0 && r<m && c<n && A[r][c]>=0)
                {
                    pq.emplace(A[r][c], r, c);
                    A[r][c] = -1;
                }
            }

        }

        return maxScore;
    }
};
int main()
{
    std::vector<vector<int>> grid;
    std::vector<int> elem;
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    // elem.push_back('X');
    elem = {5,4,5};
    grid.push_back(elem);
    elem = {1,2,6};
    grid.push_back(elem);
    elem = {7,4,6};
    grid.push_back(elem);

    Solution s;
    int score = s.maximumMinimumPath(grid);
    
    std::cout<<"max score = "<<score<<std::endl;
    return 0;
}