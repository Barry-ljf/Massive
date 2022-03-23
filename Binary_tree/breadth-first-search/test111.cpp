// it is a test
/*给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。

 */
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> ljf;
        if(root == NULL)return 0;
        ljf.push(root);
        int length =1;
        while(!ljf.empty()){
            TreeNode* record ;
            int size = ljf.size(); 
            for(int i=0; i < size; i++){
                record = ljf.front();
                ljf.pop();
                if(record->left){ljf.push(record->left);}
                if(record->right){ljf.push(record->right);}
                if(!record->left && !record->right){return length;}
            }
            length++;
        }
        return length;
    }
};