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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        swap(v[k-1],v[v.size()-k]);
        ListNode* ans = new ListNode(v[0]);
        ListNode* temp = ans;
        for(int i=1;i<v.size();i++){
            ans->next = new ListNode(v[i]);
            ans = ans->next;
        }
        return temp;
    }
};