#include<iostream>
#include<vector>
#include<stack>
#include<iterator>
#include <algorithm>
using namespace std;
/*二叉树的后序遍历*/
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
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    vector<int> result;
    if(root == NULL){return result;}
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        result.push_back(node->val);
        if(node->left){st.push(node->left);}
        if(node->right){st.push(node->right);}
    }
    reverse(result.begin(), result.end());
    return result;
  }
    // void Traversal(TreeNode* root,vector<int> &vec)
    // {
    //     if(root == NULL)return;
    //     Traversal(root->left,vec);
    //     Traversal(root->right,vec);
    //     vec.push_back(root->val);//这里就是替换一下顺序即可，后序深度搜索的话，使用的顺序应该是左右中。

    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> vec;
    //     Traversal(root,vec);
    //     return vec;
    // }
};