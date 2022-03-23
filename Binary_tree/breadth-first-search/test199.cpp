/*给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。*/
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
   vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL){return result; }
        queue<TreeNode*> ljf;
        ljf.push(root);
        while(!ljf.empty())
        {
            int size;
            size = ljf.size();
            TreeNode* node;
            vector<int> result_1;
            for(int i = 0; i < size;i++)
            {
            node = ljf.front();
            ljf.pop();
            result_1.push_back(node -> val);
            if(node->left){ljf.push(node->left);}
            if(node->right){ljf.push(node->right);}
            }
            int temp = result_1.back();//这个函数可以取vector的最后一个向量，类似的函数还有
            /*//方法一： 
            return result_1.at(result_1.size()-1);
            
            //方法二： 
            return result_1.back();
            */
            result.push_back(temp);

        }
        return result;
   }
};