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
    typedef pair<int , ListNode*>p;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            if(lists[i]){
            pq.push({lists[i]->val,lists[i]});
            }
        }
         ListNode*dummynode=new  ListNode(-1);
         ListNode*temp=dummynode;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.second->next){
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next=it.second;
            temp=temp->next;
            
        }
        return dummynode->next;
    }
};