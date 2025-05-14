class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int ans=0;
        int n=nums.size();
        vector<int>v(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                v[i]=1;
            }else{
                v[i]=0;
            }
        }

        long long cnt=0;
        long long sum=0;
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(sum%modulo==k){
                cnt++;
            }
            if(umap.find((sum-k)%modulo)!=umap.end()){
                cnt=(cnt+umap[(sum-k)%modulo]);
            }
            umap[sum%modulo]++;
        }
        return cnt;
    }
};