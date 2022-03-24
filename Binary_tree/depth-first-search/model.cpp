/*这里我想要讲一下深度优先搜索中前后序的思路*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TREEnode{
    int val;
    TREEnode *left;
    TREEnode *right;
    TREEnode();
    TREEnode(int val,TREEnode *left,TREEnode *right):val(val),left(left),right(right){}
};
vector<int> DFS(TREEnode* root)//前序遍历为例子，中序遍历请直接移步实例
{
    //首先在写这个函数的时候，一定要想好栈和遍历的顺序是怎么配合的；其次，要想好是否需要指针，遍历和操作的步骤是不是共同进行的。
    //其次，要明白，处理的目的是返回一个数组，操作就是给一个数组<vector>，然后遍历到一个数字，放进数组容器中。那么如果想要对函数实现其他功能，就在操作处理的这个地方进行改动即可
    vector<int> result;//这是要处理的数组
    stack<TREEnode*> ljf;//这是处理数据流的必备工具，想要让程序运转，就必须保证这个栈不为空，因此要在程序开始之前就在里面赋值
    ljf.push(root);
    while(!ljf.empty()){
        //我们要把扫描的全部压栈然后弹出赋值
        TREEnode *node;//这是一个帮助处理的节点
        node = ljf.top();
        ljf.pop();//把最栈顶元素用后及时剔除

        result.push_back(node->val);//这里就是遍历过程中的操作过程!!
        /*对于test226问题的翻转二叉树，实际上我们只需要遍历到每个节点的时候把他的子节点进行翻转即可，这里我们就可以把操作改为翻转操作，返回值根据函数的返回值相应更改即可*/
        //swap(node->right,node->left);

        if(node->right){ljf.push(node->right);}//这就是在处理一个子节点的时候，因为如果他有子孩子的话会把它子孩子的优先级放在前面，
        if(node->left){ljf.push(node->left);} //所以用栈这个结构，但是队列这个结构就不行，队列的先进先出适合在处理层序排列的时候，先处理同级，因此有子孩子的时候，会把子孩子家在队伍后面。

    }
    return result;
    

}
 