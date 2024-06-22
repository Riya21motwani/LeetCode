class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
       unordered_map<int,int>umap;
        int res=0;
        int cnt=0;
        umap[res]=1;
        
        for(int i=0;i<n;i++){
            cnt+=nums[i]%2;
            if(umap.count(cnt-k)){
                res+=umap[cnt-k];
            }
            umap[cnt]++;
        }
        return res;
        
        
        
        

    }
};
