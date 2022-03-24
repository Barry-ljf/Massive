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
//这里使用了三种迭代方法，我们分别理解一下这三种迭代方法是如何用同一种框架通过不同的实现来理解的,这道题目的迭代方法详见深度优先搜索的model。
class Solution {
public:
TreeNode* invertTree(TreeNode* root) {//ljf的方法
    if(root == NULL){return root;}//第一步确定终止条件，这个在二叉树里面基本就是这个。//第二步骤也就是确定返回值的类型，因为这个要承接递归的层与层
    swap(root->left,root->right);//第三步，处理单层逻辑：对于一个单层的二叉树，我要交换他的左右孩子。他的左右孩子本就应该是已经反转好的节点，因此写出这两个节点的由来，分别由左右孩子的子树翻转而来
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;

}
    TreeNode* invertTree(TreeNode* root) {
    if(root == NULL){return root;}
    swap(root->left,root->right);//单层逻辑：交换左右孩子，在这之后，我在对自己的左右孩子进行翻转，我觉得这是三层得逻辑，但是还没涉及到第三层
    invertTree(root->left);
    invertTree(root->right);
    return root;

}
    TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }
    TreeNode* left = invertTree(root->left);//单层逻辑，先求反转过子树得左右孩子，然后在对左右孩子进行赋值
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    //swap(root->left,root->right);//直接这样替换也可以
    return root;
}


};