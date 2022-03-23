/*给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include <algorithm>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> ljf;
        if(root == NULL)return result;
        ljf.push(root);
        while(!ljf.empty())
        {
            int size = ljf.size();
            vector<int> result_1;
            for(int i = 0; i<size; i++)
            {
                Node* temp;
                temp = ljf.front();
                result_1.push_back(temp->val);
                ljf.pop();
                int size_temp =0;
                size_temp = temp->children.size();
                for(int j =0;j <size_temp;j++)
                {
                    ljf.push((temp->children.at(j)));//n叉数和二叉树的主要的区别就在于，n叉树的孩子必须在这个地方全部加入到队列中才行，二叉树有左右孩子可以用但是n叉树需要用额外在用一个迭代的算法，因为他的
                                                    //子孩子本身就存储在一个容器中，所以需要对这个容器进行一个简单的遍历。
                }
                // while(!temp->children.empty())
                // {
                //     ljf.push((temp->children);
                // }

            }
             result.push_back(result_1);
        }
        return result;

        
    }
};