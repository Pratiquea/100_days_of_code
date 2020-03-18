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
private:
    unsigned int inf = std::numeric_limits<unsigned int>::max();
    // std::cout<<"infinite value = "<<inf<<std::endl;
    struct Node
    {
        Node* parent;
        int x;
        int y;
        unsigned int val; //value of current node   
        unsigned int g; //cost to come
        unsigned int t; //total cost
        long id = 1000.0*x+y;
        
        Node(int xx, int yy, unsigned int value, unsigned int dist = std::numeric_limits<unsigned int>::max()): x(xx), y(yy), val(value), g(dist), id(1000.0*x+y),parent(NULL){};
    };

    
    struct Qcompare
    {
        bool operator () ( q_element const& a,  q_element const& b){
            return a.second > b.second;
        }
    };
    

public:    
    
    int minPathSum(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int coloumns = grid[0].size();

        /// priority_queue for keeping track of lowest sum
        std::priority_queue<q_element,std::vector<q_element>,Qcompare> q;
        /// set to keep track of visited nodes
        std::set<long> visited;
        /// vector containing all nodes
        std::vector<Node *> allNodes;

        for(std::size_t i = 0; i<grid.size(); i++)
        {
            for(std::size_t j = 0; j<grid[0].size(); j++)
            {
                if(i==0 && j==0)
                {
                    Node *create_node = new Node(i,j,grid[i][j],0);
                    allNodes.push_back(create_node);
                    q.push(std::make_pair(1000*i+j,0));
                }
                else
                {
                    Node *create_node = new Node(i,j,grid[i][j],inf);
                    allNodes.push_back(create_node);
                    q.push(std::make_pair(1000*i+j,inf));
                }
                
            }
        }

        // Calling helper function for Dijkstra
        Dijkstra(grid, q, visited, allNodes, rows, coloumns);
        
        // Prinitng path
        int sum = 0;
        if(!allNodes[(rows-1)*rows+coloumns-1]->parent)
        {
            std::cout<<"No path found or sth seriously wrong"<<std::endl;
        }
        else
        {
            Node *curr = allNodes[(rows-1)*rows+coloumns-1];
            while(curr->parent != NULL)
            {
                std::cout<< curr->val <<",";
                sum += curr->val;
            }
            std::cout<<std::endl;
        }

        return sum;

     }

     void Dijkstra(vector<vector<int>>& grid, std::priority_queue<q_element,std::vector<q_element>,Qcompare>& q, std::set<long>& visited, std::vector<Node *>& allNodes, int rows, int coloumns)
     {
        
        
        std::pair<int,int> start = {0,0};
        std::pair<int,int> goal = {rows,coloumns}; 
        std::vector<std::pair<int,int>> motion = {std::make_pair(0,1),std::make_pair(1,0)};
        while(!q.empty())
        {
            q_element curr_pair = q.top();
            unsigned int xx = curr_pair.first/1000;
            unsigned int yy = curr_pair.first%1000;
            Node* curr = allNodes[xx*rows+yy];
            q.pop();
            visited.insert(curr->id);
            for(std::size_t k = 0; k<motion.size(); k++)
            {
                std::pair<int,int> step = motion[k];
                unsigned int new_x = curr->x + step.first;
                unsigned int new_y = curr->y + step.second;
                Node* child = allNodes[new_x*rows+new_y];
                if(new_x == rows && new_y == coloumns)
                {
                    child->parent = curr;
                    break;

                }
                if(!visited.count(child->id))
                {
                    if(child->g > child->val+curr->g)
                    {
                        child->g = child->val + curr->g;
                        child->parent = curr;
                        q.push(std::make_pair(child->id,child->g));
                    }
                }
            }
        }
        
        
        
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