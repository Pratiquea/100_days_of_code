#include <iostream>
#include <vector>
#include <stack>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> ans;
        ans = helper(ans,root);
        for(auto i: ans)
        {
            std::cout<<" out val = "<<i<<'\t';
        }
        return ans;
    }
    
    std::vector<int> helper(std::vector<int> ans, TreeNode* root)
    {
        if (root == NULL)
        {
            return ans;
        }
        ans = helper(ans, root->left);
        ans = helper(ans, root->right);
        ans.push_back(root->val);
        for(auto i: ans)
        {
            std::cout<<"val = "<<i<<'\n';
        }
        // std::cout<<"root val "<<root->val<<std::endl;
        return ans;
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
    std::vector<int> result;
    result = s.postorderTraversal(root);

    for(auto i: result)
    {
        std::cout<<i<<'\t';
    }
    std::cout<<'\n';

    return 0;
}