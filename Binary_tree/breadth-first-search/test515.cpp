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
/*注释掉的是carl的，剩下的没注释的是我的，在运行过程中，总会提醒这个成员可能达不到，关键就是在于没有标明是空树的特殊情况！！！！！！！！*/
// class Solution {
// public:
//     vector<int> largestValues(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root != NULL) que.push(root);
//         vector<int> result;
//         while (!que.empty()) {
//             int size = que.size();
//             int maxValue = INT_MIN; // 取每一层的最大值
//             for (int i = 0; i < size; i++) {
//                 TreeNode* node = que.front();
//                 que.pop();
//                 maxValue = node->val > maxValue ? node->val : maxValue;
//                 if (node->left) que.push(node->left);
//                 if (node->right) que.push(node->right);
//             }
//             result.push_back(maxValue); // 把最大值放进数组
//         }
//         return result;
//     }
// };
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> ljf;
        //if (root != NULL) ljf.push(root);//这一句话极其重要!!!!!!!!!!!!!
        vector<int> result;
        while(!ljf.empty()){
            int max = INT_MIN;//这里的int_min和之前的int_max要好好回忆一下！！
            int size = ljf.size();
            TreeNode* node;
            for(int i=0; i<size; i++)
            {
                node = ljf.front();
                if(node -> val >= max){max = node -> val;}
                ljf.pop();
                if(node->left){ljf.push(node->left);}
                if(node->right){ljf.push(node->right);}
            }
            result.push_back(max);


        }
        return result;

    }
};