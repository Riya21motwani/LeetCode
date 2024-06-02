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
    
    ListNode*getkthnode(ListNode*temp,int k){
        k-=1;
        
        while(k>0 &&  temp != NULL ){
             k--;
            temp=temp->next;
           
        }
        return temp;
    }
    
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
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* temp = head; 

       ListNode* prevlast = NULL; 
        
        while(temp!=NULL){
           ListNode*  kthnode=getkthnode(temp,k);
         
            
            if(kthnode==NULL){
              if(prevlast)prevlast->next=temp;
                break;
            }
            else{
             ListNode*nextnode=kthnode->next;
           kthnode->next=NULL;
            reverseList(temp);
                
                if(temp==head){
                   head=kthnode;
                }
                else{
                   prevlast->next=kthnode;
                }
                prevlast=temp;
                temp=nextnode;
            }  
        }
    
        return head;
    }
};