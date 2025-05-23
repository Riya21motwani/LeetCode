class Solution {
public:

    long long f(int ind, int flag, vector<int>& nums ,  vector<vector<long long>>&dp){
        int n=nums.size();
        long long t1=INT_MIN;
        long long t2=INT_MIN;
        if(ind==n){
           return 0;
        }

        if(dp[ind][flag]!=-1){
            return dp[ind][flag];
        }
        if(flag==0){
            t1=max(nums[ind]+f(ind+1,1,nums,dp), f(ind+1,0,nums,dp));
        }
       
        else if(flag==1){
             t2=max(-nums[ind]+f(ind+1,0,nums,dp), f(ind+1,1,nums,dp));
        }

        return dp[ind][flag]=max(t1,t2);

    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<long long>>dp(n+1,vector<long long>(2,0));
        vector<long long >prev(2,0);
        vector<long long>curr(2,0);

        for(int ind=n-1;ind>=0;ind--){
            for(int flag=0;flag<=1;flag++){
                long long t1 = LLONG_MIN;
long long t2 = LLONG_MIN;
                if(flag==0){
                 t1=max(nums[ind]+prev[1], prev[0]);
              }
       
                 else if(flag==1){
                      t2=max(-nums[ind]+prev[0], prev[1]);
             } 

              curr[flag]=max(t1,t2);
            }
            prev=curr;
        }

        return prev[0];
        
        // return f(0,0, nums,dp);
    }
};