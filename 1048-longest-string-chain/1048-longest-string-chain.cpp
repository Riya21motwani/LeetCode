class Solution {
public:

    bool isValid(string &word1, string &word2){
        int n=word1.size();
        int m=word2.size();

        if(m!=n+1){
            return false;
        }

        int i=0;
        int j=0;

        while(i<n && j<m){
            if(word1[i]==word2[j]){
                i++;
                j++;
            }else{
                j++;
            }
        }

        return i==n;
    }


    int longestStrChain(vector<string>& words) {
        int n=words.size();
      sort(words.begin(), words.end(), [](const string &a, const string &b) {
              return a.size() < b.size();
          });

        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(words[i],words[j])  && dp[i]+1 >dp[j]){
                    dp[j]=1+dp[i];
                }
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }


        return maxi;
    }
};