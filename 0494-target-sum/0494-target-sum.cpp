class Solution {
public:

    int f(int ind,int val, vector<int>& nums){
        int n=nums.size();
        if(ind==n){
            if(val==0){
                return 1;
            }
            return 0;
        }

        int notake=f(ind+1,val,nums);

        int take=0;
        if(nums[ind]<=val){
         take=f(ind+1,val-nums[ind],nums);
        }

        return take+notake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }

        if(totalsum-target<0 || (totalsum-target)%2==1){
            return 0;
        }
        int val=(totalsum-target)/2;
        return f(0,val,nums);
    }
};