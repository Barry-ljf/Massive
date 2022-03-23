
/*给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> ljf;
        if(root == NULL){return root;}
        ljf.push(root);
        while(!ljf.empty())
        {
            int size = ljf.size();
            Node* nodehead;
            Node* node;
            for(int i =0 ;i <size; i++){
                if(i == 0)
                {
                    nodehead = ljf.front();
                    ljf.pop();
                    node = nodehead;
                }else{
                    node = ljf.front();
                    ljf.pop();
                    nodehead->next = node;
                    nodehead = nodehead->next;
                }
                if(nodehead->left){ljf.push(nodehead->left);}
                if(nodehead->right){ljf.push(nodehead->right);}
            }
            nodehead->next = NULL;

        }
        return root;
        
    }
};