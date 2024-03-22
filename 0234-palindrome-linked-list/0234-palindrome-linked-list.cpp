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
           ListNode*curr=head;
               ListNode*prev=NULL;
        
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
    
   bool isPalindrome(ListNode* head){
       
       if(head==NULL || head->next==NULL) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revhead = reverseList(slow);
        prev->next = NULL;
        
        while(revhead != NULL && head != NULL) {
            if(revhead->val != head->val) {
                return false;
            }

            revhead = revhead->next;
            head = head->next;
        }

        return true;
    }
};