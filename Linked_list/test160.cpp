//it is a test
/**
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：


 */
#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
};
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *CUR_A = headA;
        ListNode *CUR_B = headB;

        while(headA == NULL && headB == NULL)return NULL;
        int length_A = 0;
        int length_B = 0;

        while(CUR_A != NULL || CUR_B != NULL){
            if(CUR_A != NULL){
                CUR_A = CUR_A->next;
                length_A++;
            }
            if(CUR_B != NULL){
                CUR_B = CUR_B->next;
                length_B++;
            }
        }
        for(int i = 0 ; i<abs(length_A -length_B);i++)
        {
            if(length_A > length_B && (headA || headB))
            {
                headA = headA->next;
            }else if(length_A < length_B && (headA || headB))
            {
                headB = headB->next;
            }
        }
        while(headA != NULL || headB != NULL){
            if(headA == headB)
            {return  headA;}
            else{
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};