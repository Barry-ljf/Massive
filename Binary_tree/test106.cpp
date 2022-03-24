// it is a test
/*给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
这道题是我认为目前来说真的很难的一道题目，因为他的单层逻辑处理的步骤很多！！！，主要还是要弄明白他的一些步骤上的逻辑*/
/*给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include <algorithm>
using namespace std;
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 ||postorder.size() == 0 )return NULL;//迭代终止条件

        int size = postorder.size();
        int LastNum = postorder[postorder.size()-1];//找到后序排列的最后一个元素
        TreeNode *root = new TreeNode(LastNum);//将一个新的节点root设置为根节点
        if(size == 1){return root;}

        int splitpoint;
        for(int i = 0; i<size; i++)
        {
            if(inorder[i]==LastNum) splitpoint = i;
        }//找到后序排列的最后一个元素在中序排列的位置

        vector<int> inorder_left(inorder.begin(),inorder.begin()+splitpoint);//对中序排列进行分离左子树
        
        vector<int> inorder_right(inorder.begin()+splitpoint+1,inorder.end());//对中序排列进行分离右子树
        postorder.resize(postorder.size()-1);
        vector<int> postorder_left(postorder.begin(),postorder.begin()+inorder_left.size());//对后序排列进行分离左子树

        vector<int> postorder_right(postorder.begin()+inorder_left.size(),postorder.end());//对后序排列进行分离右子树

        root -> left = traversal(inorder_left,postorder_left);
        root -> right = traversal(inorder_right,postorder_right);
        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if(inorder.size() == 0 ||postorder.size() == 0 )return NULL;//迭代终止条件
         return traversal(inorder,postorder);

    }
};