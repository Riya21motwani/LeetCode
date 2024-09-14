class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int>presum(n);
        presum[0]=nums[0];
        int cnt=0;
        unordered_map<int,int>umap;
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        
        for(int i=0;i<n;i++){
            
            if(presum[i]==goal){
                cnt++;
            }
            if(umap.find(presum[i]-goal)!=umap.end()){
                cnt+=umap[presum[i]-goal];
            }
            umap[presum[i]]++;
           
        }
        return cnt;
    }
};