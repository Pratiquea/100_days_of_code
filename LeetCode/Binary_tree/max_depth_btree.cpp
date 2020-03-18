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
			int maxDepth(TreeNode* root)
			{
				if(!root)
				{return 0;}
				
				return std::max(1+ maxDepth(root->left), 1+maxDepth(root->right));
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
    int result;	
	result = s.maxDepth(root);

	std::cout<<"depth = "<<result<<std::endl;
    return 0;
}
