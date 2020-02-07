// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
// using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


class Solution
{
    public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        if(root == NULL)
        {
            std::cout<<"returned nothing"<<std::endl;
            return {};
        }
        std::vector<int> TraversedList;
        stack<TreeNode *> treeStack;
        treeStack.push(root);

        While(!treeStack.empty())
        {
            
        }

        TraversedList.push_back(root->val);
        std::cout<< root->val <<std::endl;

        TraversedList = preorderTraversal(root->left);
        TraversedList = preorderTraversal(root->right);
        
        return TraversedList;
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
    std::vector<int> ans;
    ans = s.preorderTraversal(root);
    std::cout<<" got ans"<<std::endl;

    for (auto i: ans)
    {
        std::cout<<i<<'\t';
    }
    std::cout<<std::endl;
    return 0;
}