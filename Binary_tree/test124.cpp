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
        int maxval = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(root == NULL){return 0;}     
        maxSum(root);
        return maxval;

    }
    int maxSum(TreeNode* root) {
        if(root == NULL){return 0;}
        int leftmaxval = max(maxSum(root->left),0);
        int rightmaxval = max(maxSum(root->right),0);//这里的root->val,参考上一层的return指的是root->right->val
        maxval = max(leftmaxval+rightmaxval+root->val,maxval) ;//这里的root-val值得是该层的root->val
        //maxval = max(leftmaxval+rightmaxval-root->val,root->val) ;
        //if(leftmaxval <0 && rightmaxval<0)return 0;
        return max(leftmaxval,rightmaxval)+root->val;//从每一个节点选择最大的一条路
        //return maxval;
        //上面的两个root->val实际上意义不一样！！！
    }
};