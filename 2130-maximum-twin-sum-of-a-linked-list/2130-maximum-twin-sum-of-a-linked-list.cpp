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
    int pairSum(ListNode* head) {
        ListNode*node=head;
        unordered_map<int,int>umap;
        int i=0;
        while(node!=NULL){
            umap[i]=node->val;
            i++;
            node=node->next;
        }
        int n=i;
        int maxi=-1;
        for(int i=0;i<=(n/2);i++){
            int a=umap[i];
            int b=umap[n-i-1];
            int sum=a+b;
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};