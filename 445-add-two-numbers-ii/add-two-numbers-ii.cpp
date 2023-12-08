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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while(l1!=NULL){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry=0;
        ListNode* res = NULL;
        int a,b;
        while(!s1.empty() || !s2.empty()){
            a = 0;
            b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            int tot = a+b+carry;
            ListNode* temp = new ListNode(tot%10);
            carry = tot/10;
            if(res == NULL) res = temp;
            else{
                temp->next = res;
                res = temp;
            }
        }
        if(carry!=0){
            ListNode* temp = new ListNode(carry);
            temp->next = res;
            res = temp;
        }
        return res;
    }
};