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
    
    ListNode* doubleIt(ListNode* head) {
        head=reverseList(head);
         ListNode* prev=NULL;
         ListNode*curr=head;
        int c=0;
        while(curr!=NULL){
            
            int t=curr->val*2 +c;
            
            
            curr->val=t%10;
           if(t>=10){

                c=1;
           
           }else{
                  c=0;
            }
            prev=curr;
            
            curr=curr->next;
            
        }
        
        if(c!=0){
            ListNode* newnode=new ListNode(c);
            prev->next=newnode;
            
        }
        
        return reverseList(head);
        
    }
};