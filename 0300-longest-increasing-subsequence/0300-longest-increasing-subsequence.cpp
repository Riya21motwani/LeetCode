class Solution {
public:
    
    int f( vector<int>& nums, int n,int ind,int prev_index,vector<vector<int>> &dp){
         
        if(ind==n)return 0;
        if(dp[ind][prev_index+1]!=-1)return dp[ind][prev_index+1 ];
        int nottake=f(nums,n,ind+1, prev_index,dp);
        int take=0;
        if( prev_index==-1 || nums[ind]>nums[prev_index] ){
            take=1+f(nums,n,ind+1, ind,dp);
        }
        return dp[ind][prev_index+1]=max(take,nottake);
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    
    return f(nums, n, 0, -1, dp);
    }
};

