class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int small=INT_MAX;
        int ssmall=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]<small){
                small=nums[i];
            }
            else if(small<nums[i] && nums[i]<ssmall){
                ssmall=nums[i];
            }else if(nums[i]>small && nums[i]>ssmall){
                return true;
            }
        }

        return false;
    }
};