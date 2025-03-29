class Solution {
public:
//      bool solve(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
//         if(i == 0 && j == 0) return true;            
//         if(i == 0 && j > 0) return false;          
//         if(j == 0 && i > 0) {                         
//             for(int ii = 1; ii <= i; ii++) if(p[ii-1] != '*') return false;
//             return true;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         if(p[i-1] == s[j-1] || p[i-1] == '?') return dp[i][j] = solve(i-1, j-1, p, s, dp);      // matching
//          if(p[i-1] == '*') {      
//             bool notconsider = solve(i-1, j, p, s, dp);
//             bool consider = solve(i, j-1, p, s, dp);
            
//             return dp[i][j] = consider || notconsider;
//         }
//         return dp[i][j] = false;       // not matching
//     }
    
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return solve(n-1,m-1,p,s,dp);
        
        // if(i==0 && j==0)return true;
        // if(i==0 && j>0)return false;
        // if(j==0 && i>0){
        //     for(int t=1;t<i;t++)if(p[t]!='*')return false;
        //     ret
        // }
        
        dp[0][0]=true;
        bool flag=true;
         for(int i = 1; i <= n; i++) {
            bool flag = true;
            
            for(int ii = 1; ii <= i; ii++) {
                if(p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            } 

            dp[i][0] = flag;
        }
        for (int j = 1; j <= m; j++) {
              dp[0][j] = false;
          }
 
        
       
         for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                
                else if(p[i-1] == '*') {
                    bool notconsider = dp[i-1][j];
                    bool consider = dp[i][j-1];

                    dp[i][j] = consider || notconsider;
                }
                
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
        
        
        
        
       
    }
    
};