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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*dummynode=new ListNode(-1);
        dummynode->next=head;
        int cnt=right-left;
        if(head==NULL || head->next==NULL)return head;
        ListNode*prev=dummynode;
        ListNode*curr=head;
        for(int i=1;i<left;i++){
            prev=prev->next;
        }
        curr=prev->next;
       for(int i=1;i<=cnt;i++){
             ListNode* temp=prev->next;
            prev->next=curr->next;
            curr->next=curr->next->next;
            prev->next->next=temp;
            
       }
        return dummynode->next;
    }
};