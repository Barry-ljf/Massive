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

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> record;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        if (root == NULL)
        {
            return record;
        }
        while(cur !=NULL || !st.empty()){
            if(cur !=NULL)
            {
                st.push(cur);
                cur = cur->left;   
            }else
            {
                cur =st.top();
                //if(cur)
                record.push_back(cur->val);//st.top()不可以
                st.pop();
                //if(cur)
                cur = cur->right;
            }

        }
        return record;


        

    }




// public:
//     void Traversal(TreeNode* root , vector<int> &vec)
//     {
//         if(root == NULL)
//         {
//             return;
//         }
//         Traversal(root->left,vec);
//         vec.push_back(root->val);
//         Traversal(root->right,vec);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> vec;
//         Traversal(root,vec);
//         return vec;
//     }

};