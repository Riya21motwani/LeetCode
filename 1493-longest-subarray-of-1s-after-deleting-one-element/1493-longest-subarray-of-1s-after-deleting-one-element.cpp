class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        int i=0;
        int j=0;
        int maxi=0;
        while(j<n){
            if(nums[j]==0){
                cnt0+=1;
            }

            while(cnt0>1){
                if(nums[i]==0){
                    cnt0--;    
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi-1;
    }
};