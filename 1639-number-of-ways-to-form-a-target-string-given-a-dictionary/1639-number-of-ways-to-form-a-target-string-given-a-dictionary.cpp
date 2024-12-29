class Solution {
public:


     int mod = 1e9+7;
    
    int f(int i, int j,vector<vector<long long>>&table,vector<string>& words, string &target , int m ,vector<vector<int>>&dp){

            if(i==target.size()){
                return 1;
            }
            if(j==m){
                return 0;
            }

            if(dp[i][j]!=-1){
                return dp[i][j];
            }

            int notake=f(i,j+1,table,words,target,m,dp)%mod;
            int take=(table[target[i]-'a'][j]*f(i+1,j+1,table,words,target,m,dp))%mod;
            
            return dp[i][j]=(take+notake)%mod;
    }


    int numWays(vector<string>& words, string target) {
        int n=words.size();
        int m=words[0].size();
         vector<vector<long long>>table(26,vector<long long>(m,0));

         vector<vector<int>>dp(1001,vector<int>(1001,-1));

         for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                table[words[i][j]-'a'][j]=1+table[words[i][j]-'a'][j];
            }
         }

         return f(0,0,table,words,target,m,dp);
    }
};