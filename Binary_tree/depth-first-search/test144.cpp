#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*二叉树的前序遍历*/

/*递归法就不说什么了，非递归的方法就是要用到栈，中左右和左右中都是访问即出栈，但是左中右不可以，
因此需要加个指针栈和指针都是二叉树类型的，是因为栈存储二叉树类型可以使得往回走的时候仍然是二叉树节点，
指针就是压到栈里的内容，自然也是二叉树类型*/
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
/*递归法*/
    void Traversal(TreeNode* root , vector<int> &vec)//容器定义的数组，必须使用取值符来确定地址
    {
        if(root == NULL){return;}
        vec.push_back(root->val);
        Traversal(root->left,vec);
        Traversal(root->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        Traversal(root , vec);
        return vec;
    }
/*迭代法*/
     vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* record = st.top();
           
            result.push_back(record->val);
             st.pop();
            if(record->right){st.push(record->right);}
            if(record->left){st.push(record->left);}

        }

        return result;

     }
};
        

// int main()
// {
//     vector<int> v{1,2,3,4,5,6,7,8,9,10};;
//     TreeNode* input  = v;
//     Solution preorderTraversalhh;
//     vector<int> v1 = preorderTraversalhh.preorderTraversal(v);
    
//  for (int i = 0; i < v.size(); ++i)
//         cout << v[i] <<" "; //像普通数组一样使用vector容器
//     return 0;
// }
