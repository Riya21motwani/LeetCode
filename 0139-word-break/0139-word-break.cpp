class Solution {
public:
    
    bool solve(int ind, string &s, unordered_set<string>&uset , int n , vector<int>&dp){
        if(ind>=n){
            return true;
        }
        if(uset.find(s)!=uset.end()){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i=1;i<=n;i++){
            string temp=s.substr(ind,i);
            if(uset.find(temp)!=uset.end() && solve(ind+i,s,uset,n,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
      int n=s.size();
        vector<int>dp(n+1,-1);
        unordered_set<string>uset;
        for(int i=0;i<wordDict.size();i++){
            uset.insert(wordDict[i]);
        }
        return solve(0, s,uset,n , dp);
    }
};