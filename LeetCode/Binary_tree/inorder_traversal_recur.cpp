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
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        result = helper(root,result);

        return result;
    }

    std::vector<int> helper(TreeNode *root, std::vector<int> result)
    {
        if(root != NULL)
        {
            if(root->left != NULL){
                result = helper(root->left, result);
            }
            
            result.push_back(root->val);
            std::cout<<"val pushed = "<<root->val<<std::endl;

            if(root->right != NULL){
                result = helper(root->right,result);
            }

        return result;
        }

        // return result;
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