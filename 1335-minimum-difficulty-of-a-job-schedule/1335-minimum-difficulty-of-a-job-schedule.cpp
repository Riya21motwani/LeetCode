class Solution {
public:

    int f(int ind, int d, vector<int>& jobDifficulty , int n , vector<vector<int>>&dp){

        if(d==1){
            int maxi=-1;
            for(int i=ind;i<n;i++){
                maxi=max(maxi,jobDifficulty[i]);
            }
            return maxi;
        }

        if(dp[ind][d]!=-1){
            return dp[ind][d];
        }
        int maxi=-1;
        int res=INT_MAX;

        for(int i=ind;i<=n-d;i++){
            maxi=max(maxi,jobDifficulty[i]);
            int ans=maxi+f(i+1,d-1, jobDifficulty,n,dp);
            res=min(res,ans);
        }

        return dp[ind][d]=res;
        
    }



    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();

        vector<vector<int>>dp(301,vector<int>(11,-1));
        if(d>n){
            return -1;
        }

        return f(0,d,jobDifficulty,n,dp);
    }
};