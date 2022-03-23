/*给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include <algorithm>
using namespace std;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> ljf;
        vector<vector<int>> result;
        if(root != NULL)ljf.push(root);
        while(!ljf.empty())
        {
            vector<int> result_1;
            int size = ljf.size();
            for(int i = 1; i<= size; i++)
            {
                TreeNode* bump;
                bump = ljf.front();
                ljf.pop();
                result_1.push_back(bump->val);
                if(bump->left){ljf.push(bump->left);}
                if(bump->right){ljf.push(bump->right);}
            }
            result.push_back(result_1);


        }
        return result;

    }
};
