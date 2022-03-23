// it is a test
/* 给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

*/
//如果使用广度优先遍历的办法，求最大最小深度实际上只相差了两行代码，对于左右子树都没有的情况，最小深度就是直接return，最大深度就是全部遍历完记录层数即可
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
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == 0)
//         {return 0;}
//         int leftdepth = maxDepth(root->left);
//         int rightdepth = maxDepth(root->right);
//         int result = leftdepth < rightdepth? rightdepth:leftdepth;
//         return result + 1 ;
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> ljf;
        if(root == NULL)return 0;
        ljf.push(root);
        int length =0;
        while(!ljf.empty()){
            TreeNode* record ;
            int size = ljf.size(); 
            for(int i=0; i < size; i++){
                record = ljf.front();
                ljf.pop();
                if(record->left){ljf.push(record->left);}
                if(record->right){ljf.push(record->right);}
            }
            length++;
        }
        return length;
    }
};