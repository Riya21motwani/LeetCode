class Solution {
public:

    bool f(int ind, int open, string s, int n , vector<vector<int>>&dp){
        if(ind==n){
            return open==0;
        }
        if(dp[ind][open]!=-1){
            return dp[ind][open];
        }
        bool valid=false;
        if(s[ind]=='*'){
                valid = f(ind+1,open+1,s,n,dp) | f(ind+1,open, s,n,dp);
                if(open>0){
                    valid |=f(ind+1,open-1,s,n,dp);
                }
        }
        else if(s[ind]=='('){
            valid |=f(ind+1,open+1,s,n,dp);
        }else if(open>0){
            valid|=f(ind+1,open-1,s,n,dp);
        }

        return dp[ind][open]=valid;
    }

    bool checkValidString(string s) {
        
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // return f(0,0,s,n,dp);

        dp[n][0]=true;

        for(int ind=n-1;ind>=0;ind--){
            for(int open=n-1;open>=0;open--){
                bool valid=false;
               if(s[ind]=='*'){
                valid = dp[ind+1][open+1]| dp[ind+1][open] ;
                 if(open>0){
                      valid |=dp[ind+1][open-1];
                  }
                }
              else if(s[ind]=='('){
                 valid |=dp[ind+1][open+1];
              }else if(open>0){
            valid|=dp[ind+1][open-1];
           }

             dp[ind][open]=valid;
            }
        }
        return dp[0][0];
    }
};