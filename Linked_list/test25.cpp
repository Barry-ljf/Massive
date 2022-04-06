//it is a test
/**
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。

如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 */
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
    ListNode(int val):val(val),next(NULL){}
    ListNode(int val,ListNode *next):val(0),next(next){}
};//结构体和类都需要加分号
class Solution {
public://这里面一共有四个指针在处理大数组，针对每一个子链的头尾节点可以作为输入输出带入一个函数进行翻转
    pair<ListNode*  ,ListNode*  > reverse(ListNode* head ,ListNode* tail){
        ListNode* prev = tail -> next;//类似于环形的循环列表，代替第一个节点指向的NULL，可以节省空间
        ListNode* p = head;//保留头节点

        while(prev != tail){//转一圈回到最后一个值，关键在于记录可执行的最后一个节点
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead = new ListNode(0);//为了确定返回值的头节点
        prehead -> next = head;
        ListNode* pre = prehead;
        ListNode* tail = prehead;
        while(head){
        
        for(int i =0 ; i< k; i++){
            tail = tail->next;
            if( !tail )
            {
                return prehead->next;//在这里结束说明已经把节点的值更改完毕，可以返回。
            }
        }
        ListNode* nex = tail ->next;//到这里出现了四个值pre、head、tail、nex可以对head、tail操作

        pair<ListNode*  ,ListNode*  > result;
        // ListNode* head_1;
        // ListNode* tail_1;//这里切记不能找新的值来代替，要保证原来的值能衔接的上，因为逻辑上用的head值是head_1
        result = reverse(head,tail);
        head = result.first;
        pre->next = head;//连接
        //pre->next = tail;
        tail = result.second;
        tail->next = nex;//连接

        head = tail->next;//确定新的头部
        pre = tail;//确定新的pre
        }
        return prehead->next;

    }
};