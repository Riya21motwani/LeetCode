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
    
    int findlength(ListNode* head){
        int len=0;
        ListNode*currr=head;
        while(currr!=NULL){
            len++;
            currr=currr->next;
        }
        return len;
        
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=findlength(head);
        
        int parts= length/k;
        int rem=length%k;
        vector<ListNode*>res(k,NULL);
        ListNode*curr=head;
        ListNode*prev=NULL;
        for(int i=0;i<k;i++){
            res[i]=curr;
            for(int j=1;j <=length/k +(rem>0) ? 1 : 0 ;j++ ){
                prev=curr;
                curr=curr->next;
            }
            if(prev!=NULL){
            prev->next=NULL;
            }
            rem--;
        }
       return res;
    }
};