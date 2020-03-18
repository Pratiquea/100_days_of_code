#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
        // std::queue<TreeNode*> q;
        std::vector<std::vector<int>> ans;
        ans = helper(root, ans, 0);
        return ans;
    }

    std::vector<std::vector<int>> helper(TreeNode* root, std::vector<std::vector<int>>& ans, int level)
    {
        if(!root)
        {
            return ans;
        }
        
        print("size = ",ans.size());
        if(ans.size()<level+1)
        {
            std::vector<int> temp;
            temp.push_back(root->val);
            ans.push_back(temp);
        }
        else
        {
            ans[level].push_back(root->val);
        }
        
        ans = helper(root->left, ans, level+1);
        ans = helper(root->right, ans, level+1);
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
