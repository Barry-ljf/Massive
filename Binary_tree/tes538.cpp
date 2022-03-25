// it is a test
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    int presum;
    void traversal(TreeNode* root) {
        if(root == NULL)
        {
            return; 
        }
        traversal(root->right);
        root->val += presum;
        presum = root->val;

        traversal(root->left);

        

    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
        {
            return root; 
        }
        traversal(root);
        return root;
    
    }
};