/*给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历*/
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> ljf;
        vector<vector<int>> result;
        if(root != NULL){ljf.push(root);}
        while(!ljf.empty())
        {
            vector<int> result_1;
            int size = ljf.size();
            for(int i = 1; i <= size; i++ )
            {
                TreeNode* node;
                node = ljf.front();
                result_1.push_back(node->val);
                ljf.pop();
                if(node->left){ ljf.push(node->left);}
                if(node->right){ ljf.push(node->right);}

            }
            result.push_back(result_1);
           

        }
         reverse(result.begin(),result.end());//实际上就是正序遍历的reverse，注意函数的使用方法
         return result;


    }
};