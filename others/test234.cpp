#include<iostream>
#include<vector>
using namespace std;
/*给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
没做完尝试用O(1)做
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
    ListNode(int val):val(val),next(NULL){}
    ListNode(int val,ListNode *next):val(0),next(next){}
};//结构体和类都需要加分号
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* cur = head;
        vector<int> val1;
        while(cur != NULL){
            val1.push_back(cur->val);
            cur = cur->next;
        }
        for(int i =0, j =val1.size()-1;i<j;i++,j--){
            if(val1[i] != val1[j]) {
                return false;
            }
        }
        return true;

    }
};