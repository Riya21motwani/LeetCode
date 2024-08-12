class Solution {
public:
    
    bool f( vector<int>& nums , int ind , int n , vector<int>&dp){
        if(ind>n-1)return false;
        if(ind==n-1)return true;
        if(nums[ind]==0 && ind!=n-1) return false;
        
        if(dp[ind]!=-1)return dp[ind];
        
        for(int i=nums[ind] ; i>0  ;i--){
           if(f(nums,ind+i , n , dp)==true)return true;
        }
        return dp[ind]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(nums, 0 ,n , dp);
    }
};