// it is a test
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> ljf;
        vector<double> average;
        if(root == NULL){return average;}
        ljf.push(root);
        while(!ljf.empty())
        {
            int size;
            size = ljf.size();
            double average_1 = 0;
            for(int i = 0; i < size;i++)
            {
                TreeNode* node;
                node = ljf.front();
                ljf.pop();
                average_1 = average_1 + node->val;
                if(node->left){ljf.push(node->left);}
                if(node->right){ljf.push(node->right);}
            }
            average_1 = average_1/double(size);
            average.push_back(average_1);
        }
        return average;


    }
};