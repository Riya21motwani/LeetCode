class Solution {
public:

    bool f(int i, int j , int k, string s1, string s2, string s3 , vector<vector<vector<int>>>&dp){

        if(i<0 && j<0 && k<0){
            return true;
        }
        if( i<0 && j< 0 && k>=0){
            return false;
        }
        if(dp[i+1][j+1][k+1]!=-1){
            return dp[i+1][j+1][k+1];
        }
        bool t1=false;
        bool t2=false;
        if(i>=0 && k>=0 &&s1[i]==s3[k]){
           t1= f(i-1,j,k-1,s1,s2,s3,dp);
          
            
        }
        if(j>=0 && k>=0 && s2[j]==s3[k]){
           t2=f(i,j-1,k-1,s1,s2,s3,dp);
                
        }
        return dp[i+1][j+1][k+1]= t1|| t2;
    }
    

    bool isInterleave(string s1, string s2, string s3) {
        int n3=s3.size();
        int n2=s2.size();
        int n1=s1.size();
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, -1)));
        if(n1+n2 !=n3){
            return false;
        }

        return f(n1-1,n2-1,n3-1,s1,s2,s3,dp);

        
    }
};