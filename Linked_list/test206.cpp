//it is a test
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre  = new ListNode;
        ListNode* temp;
        ListNode* cur = head;
        if(head == NULL)return head;
        temp = cur -> next;
        cur -> next = NULL;
        pre = cur;
        cur = temp;

        while(cur != NULL){
            temp = cur -> next;
             cur -> next = pre;
             pre = cur;
             cur = temp;
        }
        return pre ;


    }
};