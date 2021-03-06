#include <iostream>
#include <vector>
#include <stack>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL){};
};

class Solution{
    public:

    std::vector<int> inorderTraversal(TreeNode *root){
        if(root == NULL){
            return std::vector<int>();
        }
        std::vector<int> result;
        std::stack<TreeNode *> stk;
        TreeNode *curr = root;

        while(curr != NULL || !stk.empty())
        {
            while(curr != NULL){
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            result.push_back(curr->val);
            std::cout<<"pushed value "<<curr->val<<std::endl;
            stk.pop();
            curr = curr->right;
        }
        return result;
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
    result = s.inorderTraversal(root);

    for(auto i: result)
    {
        std::cout<<i<<'\t';
    }
    std::cout<<'\n';

    return 0;
}