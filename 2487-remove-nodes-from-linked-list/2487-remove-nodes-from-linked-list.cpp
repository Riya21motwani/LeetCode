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
    
    ListNode* reverseList(ListNode* head) {
         ListNode*prev=NULL;
         ListNode*curr=head;
        
        if(head==NULL || head->next==NULL)return head;
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
   
    
    ListNode* removeNodes(ListNode* head) {
        
        head=reverseList(head);
        int maxi=-1;
        ListNode*prev=NULL;
        ListNode*curr=head;
        while(curr!=NULL){
                  maxi=max(maxi,curr->val);
                   if(curr->val<maxi){
                       prev->next=curr->next;
                       ListNode*temp=curr;
                       curr=curr->next;
                       delete(temp);
                   }
            else{
                     prev=curr;
                curr=curr->next;
            
            }
        }
        return reverseList(head);
    }
};