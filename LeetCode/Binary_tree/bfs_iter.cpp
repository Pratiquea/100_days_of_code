#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x),left(NULL),right(NULL){};
};

class Solution
{
    public:
    std::vector<std::vector<int>> bfs(TreeNode* root)
    {
        std::queue< std::pair<TreeNode*, int>> q;
        std::vector<std::vector<int>> ans;
        int level = 0;
        std::pair<TreeNode*,int> first;
        first = std::make_pair(root, level);
        q.push(first);
        while(!q.empty())
        {
            first = q.front();
            root = first.first;
            level = first.second;
            q.pop();

            if(!root)
            {return ans;}

            if(ans.size()<level+1)
            {
                std::vector<int> level_element;
                level_element.push_back(root->val);
                ans.push_back(level_element);
            }
            else
            {
                ans[level].push_back(root->val);
            }

            if(root->left)
            {
                std::pair<TreeNode*, int> temp;
                temp = std::make_pair(root->left,level+1);
                q.push(temp);
            }

            if(root->right)
            {
                std::pair<TreeNode*, int> temp;
                temp = std::make_pair(root->right,level+1);
                q.push(temp);
            }
        }

        return ans;
    }

    template<typename str, typename val>
    void print(str s, val v)
    {
        std::cout<< s << v << std::endl;
    }
};


int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    std::vector<std::vector<int>> result;
    result = s.bfs(root);

    for(auto i: result)
    {
        for(auto j:i)
        {
            std::cout<<j<<'\t';
        }
        std::cout<<'\n';
    }

    return 0;
}
