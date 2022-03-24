// it is a test
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        //递归问题的第一步永远都是找到终止的条件
        //找到第一的值
        int size = preorder.size();//这一步不需要了
        if(preorder.size()==0 || inorder.size()==0){return NULL;}
        int First_num = preorder[0];
        TreeNode* root = new TreeNode(First_num);
        if(size == 1)return root;//这里把终止条件给些圆满了算是如果俩序列都是0，则直接返回NULL，如果说前序只有一个值，那就直接返回这个值既可。
                                 //因为他没办法继续分割了，不想一个完整的子树节点，还能返回给中序数列让他寻找分割点，只有一个节点的前序是没有必要再分的
        
        //找到该数字再中序数列中的坐标，也就是分离点
        int splitnum;
        for(int i =0; i<size; i++){
            if(inorder[i] == First_num){splitnum = i;}
        }

        //对分离点的左右进行分离为左孩子和右孩子
        vector<int>inorder_left(inorder.begin(),inorder.begin()+splitnum);
        vector<int>inorder_right(inorder.begin()+splitnum+1,inorder.end());

        /*这个105和106的主要差别就在于这一行代码，实际上逻辑搞清楚之后还是十分好写的，这里主要就是为了删除第一个元素，因为他是之前的头节点，应该被剔除的！*/
        preorder.erase(preorder.begin());



        vector<int>preorder_left(preorder.begin(),preorder.begin()+inorder_left.size());
        vector<int>preorder_right(preorder.begin()+inorder_left.size(),preorder.end());//注意两者拆分时的不同，这里的拆分是没有中间值，因为中间值前面
        
        root -> left = traversal(preorder_left,inorder_left);
        root -> right =  traversal(preorder_right,inorder_right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0){return NULL;}
        return  traversal(preorder,inorder);
    }
};