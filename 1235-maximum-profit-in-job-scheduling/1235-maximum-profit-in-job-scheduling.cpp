class Solution {
public:
    int f(int ind, int end , vector<vector<int>>&v){
        int l=ind;
        int n=v.size();
        int h=n-1;
        int ans=n+1;
        while(l<=h){
            int mid=(l+h)/2;
            if(end<=v[mid][0]){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int solve( int i,vector<vector<int>>&v , vector<int>&dp){
        int n=v.size();
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int nexidx=f(i+1,v[i][1],v);
        int take=v[i][2]+solve( nexidx ,v,dp);
        int notake=solve(i+1,v,dp);
        return dp[i]=max(take,notake);
    }


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>>v(n,vector<int>(3,0));
        vector<int>dp(n, -1);

        for(int i=0;i<n;i++){
            v[i][0]=startTime[i];
            v[i][1]=endTime[i];
           v[i][2]=profit[i];
            
        }
        sort(v.begin(),v.end());
        return solve(0,v,dp);
    }
};