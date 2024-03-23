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
    
    ListNode*reverse(ListNode*head){
      ListNode*curr=head;
          ListNode*prev=NULL;
          ListNode*temp=curr->next;
        
        while(temp!=NULL){
            
            curr->next=prev;
            prev=curr;
            curr=temp;
            temp=temp->next;
            
        }
        
        curr->next=prev;
        prev=curr;
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode*curr=head;
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*revhead=reverse(slow);
        while(revhead->next!=NULL){
             ListNode*temp=head->next;
             ListNode*temprev=revhead->next;
            head->next=revhead;
            revhead->next=temp;
            head=temp;
            revhead=temprev;
        }
    }
};