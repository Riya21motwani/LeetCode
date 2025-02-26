class Solution {
public:

    int maxival(vector<int>&nums){
         int n=nums.size();
         int curr=nums[0];
         int maxi=nums[0];
         for(int i=1;i<n;i++){
            curr=max(curr+nums[i],nums[i]);
            maxi=max(maxi,curr);
         }
         return maxi;
    }
    int minival(vector<int>&nums){
         int n=nums.size();
         int curr=nums[0];
         int mini=nums[0];
         for(int i=1;i<n;i++){
            curr=min(curr+nums[i],nums[i]);
            mini=min(mini,curr);
         }
         return mini;
    }



    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();

        return max(abs(minival(nums)), maxival(nums));
    }
};