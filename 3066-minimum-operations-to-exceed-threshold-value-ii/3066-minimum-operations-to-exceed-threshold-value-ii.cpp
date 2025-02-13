class Solution {
public:

    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        
        

        priority_queue<long long,vector<long long>,greater<long long>>pq;

        for(auto it:nums){
            pq.push(it);
        }

        while(!pq.empty()){
            long long el1=pq.top();
            pq.pop();
            long long  el2=-1;
            if (!pq.empty()){
            el2=pq.top();
           pq.pop();
            }
            if(el1>=k){
                return cnt;
            }
            cnt++;

            long long  val=min(el1,el2)*2+max(el1,el2);

            pq.push(val);

        }

        return cnt;
    }
};
