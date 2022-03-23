/*给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL

*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include <algorithm>
using namespace std;
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
            Node* node1;//记录头节点
            Node* node2;
            for(int i = 0; i< size; i++)
            {
                if(i == 0)
                {
                    node1 = ljf.front();//每次取队列的设为一个变量
                    ljf.pop();
                    node2 = node1;

                }
                else{
                    node1 =  ljf.front();
                    ljf.pop();
                    node2 -> next = node1;
                    node2 = node2->next;
                }
            if(node1->left){ljf.push(node1->left);}
            if(node1->right){ljf.push(node1->right);}
 
            }
            node2->next = NULL;
            
        }
        return root;
    }
};//可运行
/*这两个函数在node这个地方的差异导致了运行的错误找出他*/
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> ljf;
        if(root == NULL){return root;}
        ljf.push(root);
        while(!ljf.empty())
        {
            int size = ljf.size();
            Node* node1;//记录头节点
            Node* node2;
            for(int i = 0; i< size; i++)
            {
                if(i == 0)
                {
                    node1 = ljf.front();
                    ljf.pop();
                    node2 = node1;//到这里没毛病

                }
                else{
                    node1 =  ljf.front();
                    ljf.pop();
                    node2 -> next = node1;//目前来说node1是队列头，是第二个节点！！！
                    node1 = node1->next;//这个操作不正确的地方在于，node1->next存在
                    //node2 = node2->next;
                }
                if(node1 -> left){ljf.push(node1 -> left);}
                if(node1 -> right){ljf.push(node1 -> right);}
            }
            node1->next = NULL;//应该找到上述循环的最后一个节点，node1或者node2都可以。
        }
        return root;
    }
};//不可运行