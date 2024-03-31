class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long n=nums.size();
        int notreq=-1;
        int miniKpos=-1;
        int maxiKpos=-1;
        long long ans=0;
        long long temp=0;
        for(int i=0;i<n;i++){
             if(nums[i] <minK || nums[i]>maxK){
                   notreq=i;
             }
            if(nums[i]==minK){
               miniKpos=i;
            }
            if(nums[i]==maxK){
               maxiKpos=i;
            }
            temp=min(miniKpos,maxiKpos)-notreq;
            ans+=(temp<=0)?0:temp;
        }
        return ans;
    }
};