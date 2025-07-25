class Solution {
public:


    int f(int i , int j , vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int maxi=0;
        for(int k=i;k<=j;k++){
            maxi=max(maxi , nums[i-1]*nums[k]*nums[j+1]  + f(i,k-1,nums,dp)+f(k+1,j,nums,dp));
        }
        return dp[i][j]=maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n= nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return f(1,n,nums,dp);
    }
};