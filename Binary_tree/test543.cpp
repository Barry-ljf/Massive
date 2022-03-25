// it is a test
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int maxval = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){return 0;}
        maxdepth(root);
        return maxval;

    }
    int maxdepth(TreeNode* root) {
        if(root == NULL){return 0;}

        int leftdepth = maxdepth(root->left);
        int rightdepth = maxdepth(root->right);
        maxval = max(leftdepth + rightdepth ,maxval);
        return max(leftdepth,rightdepth) + 1;//从终止条件分析，return 0的时候实际上是一层那么无论是左子树还是右子树，长度都要加1.要不然这里加1，要不然在rightdepth，leftdepth都相应加1.
        
    }
};