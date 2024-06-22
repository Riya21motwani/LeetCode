class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt1=0;
        int cnt0=0;
        int maxi=0;
        while(j<n){
            
            if(nums[j]==0)cnt0++;
            if(nums[j]==1){
                cnt1++;
                
            }
            if(cnt1==n){
                return cnt1-1;
            }
            
            
                while(cnt0>1){
                    if(nums[i]==0)cnt0--;
                   else if(nums[i]==1)cnt1--;
                    i++;
                }
            
            j++;
            maxi=max(maxi,cnt1);
            
        }
        return maxi;
    }
};