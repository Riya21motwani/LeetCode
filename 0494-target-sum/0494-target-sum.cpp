class Solution {
public:
    int cnt=0;
    void f(int ind,vector<int>& nums, int target , int val){
        int n=nums.size();
        if(ind==n){
            if(val==target){
                cnt++;

            }
            return;
        }

        f(ind+1,nums,target,val+nums[ind]);
        f(ind+1,nums,target,val-nums[ind]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
        
         f(0,nums,target, 0);
         return cnt;
    }
};