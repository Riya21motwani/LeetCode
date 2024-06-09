class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       int n=nums.size();
        unordered_map<int,int>umap;
        int ans=0;
        umap[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           int rem=sum%k;
            if(rem<0){ 
                rem+=k;
            }
            if(umap.find(rem)!=umap.end()){
                ans+=umap[rem];
            }
            umap[rem]++;
        }
        return ans;
    }
};