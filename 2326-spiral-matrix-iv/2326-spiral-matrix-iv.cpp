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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>spiral(m,vector<int>(n,-1));
        
        ListNode* temp=head;
        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        int dir=0;
        while(top<=bottom && left<=right  ){
            if(dir==0){
                for(int i=left;temp!=NULL &&  i<=right;i++){
                    
                    
                   spiral[top][i]=temp->val;
                    
                    temp=temp->next;
                    
                }
            top++;
           }
            
            if(dir==1){
               for(int i=top;temp!=NULL && i<=bottom ;i++){
                   spiral[i][right]=temp->val;
                   
                    temp=temp->next;
                    
               }
                right--;
            }
            
            if(dir==2){
                for(int i=right;temp!=NULL &&  i>=left;i--){
                   spiral[bottom][i]=temp->val;
                   
                    temp=temp->next;
                   
                    
                }
            bottom--;
           }
            
            
            if(dir==3){
               for(int i=bottom;temp!=NULL && i>=top ;i--){
                   spiral[i][left]=temp->val;
                  
                    temp=temp->next;
                    
                   
               }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        }
        return spiral;
    }
};