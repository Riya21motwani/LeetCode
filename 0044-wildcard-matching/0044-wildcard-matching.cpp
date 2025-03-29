class Solution {
public:

//     bool f(int i, int j , string s, string p ,  vector<vector<int>>&dp){

//        if(i<0 && j<0){
//         return true;
//        }
//        if(i>=0 && j<0){
//         return false;
//        }

//        if(i<0 && j>=0){
//         for(int l=0;l<=j ;l++){
//             if(p[l]!='*'){
//                 return false;
//             }
//         }
//         return true;
//        }
       

//        if(dp[i][j]!=-1){
//         return dp[i][j];
//        }

//         if(s[i]==p[j] || p[j]=='?'){
//             return dp[i][j] = f(i-1,j-1,s,p,dp);
//         }
    
//           if(p[j]=='*') 
//          {
//            return  dp[i][j]=f(i,j-1,s,p,dp) || ( f(i-1,j,s,p,dp));
//          }

//          return dp[i][j]=false;
//     }
//     bool isMatch(string s, string p) {
//         int n=s.size();
//         int m=p.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         return f(n-1,m-1,s,p , dp);
//     }
// };

    
    bool f(int i,int j,  string &p, string &s,vector<vector<int>>&dp){
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false;
        if(i>=0 && j<0){ for(int ii = 0; ii <= i; ii++) if(p[ii] != '*') return false;
            return true;
           
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(p[i]==s[j] || p[i]=='?'){
             return dp[i][j]= f(i-1,j-1,p,s,dp);
        }
      
        else if(p[i]=='*'){
            return dp[i][j]=f(i,j-1,p,s,dp) || f(i-1,j,p,s,dp);
        }
        
       return dp[i][j]=false;
    }
    

    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,p,s,dp);
    }
};