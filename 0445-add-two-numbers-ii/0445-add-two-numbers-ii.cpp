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
            ListNode*prev=NULL;
            ListNode*curr=head;
            ListNode*nextnode=NULL;
            while(curr!=NULL){
                nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
            }

            return prev;

    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*newl1=reverse(l1);
        ListNode*newl2=reverse(l2);
        int carry=0;
        ListNode*prev=NULL;
        ListNode*newhead=prev;
        while(newl1!=NULL || newl2!=NULL|| carry!=0){


            int sum=carry;

            if(newl1!=NULL){
                sum+=newl1->val;
                newl1=newl1->next;
            }
            if(newl2!=NULL){
                sum+=newl2->val;
                newl2=newl2->next;
            }
                
                carry=sum/10;
                sum=sum%10;
            
            ListNode*newnode=new ListNode(sum);
            if(prev!=NULL){
                prev->next=newnode;
            }else {
                newhead = newnode; 
            }
            prev=newnode;
           
        }

        
        return reverse(newhead);



    }
};