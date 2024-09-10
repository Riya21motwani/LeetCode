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
    
    int find(int element1 , int element2){
         int minielement=min(element1, element2);
        for(int i=minielement;i>=1;i--){
            if(element1%i==0 && element2%i==0){
                return i;
            }
        }
      return 1;
    }
    
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*temp=head;
        while(temp->next!=NULL){
            int el1=temp->val;
            ListNode*previous=temp;
            if(temp->next!=NULL){
            temp=temp->next;
            }
            int el2=temp->val;
            
            int findnewnode= find(el1, el2);
            ListNode* newnode= new ListNode(findnewnode);
            previous->next=newnode;
            newnode->next=temp;
            
        }
        
        return head;
    }
};