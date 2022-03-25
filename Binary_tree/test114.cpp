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
    void flatten(TreeNode* root) {
        stack<TreeNode*> ljf;
        if(root == NULL) {return;}
        else{
        TreeNode* prenode = new TreeNode(-1);
        ljf.push(root);
        while(!ljf.empty())
        {
            TreeNode* temp;
            temp = ljf.top();
            prenode->right = temp;
            prenode->left = nullptr;
            prenode = prenode->right;

            ljf.pop();

            if(temp->right){ljf.push(temp->right);}
            if(temp->left){ljf.push(temp->left);}

        }
        //root->left = nullptr;
        root = prenode->right;
        }

    }
};