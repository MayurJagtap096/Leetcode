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

    int getSizeOfLinkedList(ListNode* head, int s)
    {
        if(head == NULL)
            return s;
        return getSizeOfLinkedList(head->next, s+1);
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<ListNode*> ans(k,NULL);
        if(head==NULL) return ans;
        int s = getSizeOfLinkedList(head, 0);

        int eachBucketSize = s/k;
        int remainingNodes = s%k;

        ListNode* curr = head;
        ListNode* prev = NULL;

        for(int i=0;i<k;i++)
        {
            ans[i] = curr;
            for(int count = 1;count <= eachBucketSize + (remainingNodes>0 ? 1 : 0);count++)
            {
                prev = curr;
                curr = curr->next;
            }
            if(prev!=NULL)
                prev->next=NULL;
            
            remainingNodes--;
        }
        return ans;
    }       
};