#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
        std::stack<TreeNode*> stk;
        // TreeNode* curr = root;
        stk.push(root);
        while(!stk.empty() )
        {
            root = stk.top();
            ans.push_back(root->val);
            // print(root->val," inside");
            stk.pop();
            if(root->left)
            {
                stk.push(root->left);
            }
            if(root->right)
            {
                stk.push(root->right);
            }
        }
        std::reverse(ans.begin(),ans.end());
        
        return ans;
    }
    template<typename T, typename T2>
    void print(T val, T2 name)
    {
        std::cout<< "output in " <<name<<" = "<< val << std::endl;
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