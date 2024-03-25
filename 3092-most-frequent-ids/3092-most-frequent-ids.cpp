class Solution {
public:
    typedef long long ll;
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n=nums.size();
        vector<ll>ans(n);
        unordered_map<ll,ll>umap;
        priority_queue<pair<ll,ll>>pq;
        
        for(int i=0;i<n;i++){
            int id=nums[i];
            int f=freq[i];
           umap[id]+=f;
            pq.push({umap[id],id});
            while(umap[pq.top().second]!=pq.top().first){
             pq.pop();
            }
            ans[i]=pq.top().first;
        }
        return ans;
    }
};