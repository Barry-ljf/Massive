// it is a test
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
    bool helper(TreeNode* root, long long lower, long long upper)
    {
        if(root == nullptr){return true;}
        if(root->val>=upper || root->val<=lower){return false;}
        
        //return true;

        return helper(root->left,lower,root->val)&&helper(root->right,root->val,upper);
    }
    bool isValidBST(TreeNode* root) {
        // int lower = LONG_MIN;
        // int upper = LONG_MAX;
        return helper(root, LONG_MIN, LONG_MAX);

    }
};