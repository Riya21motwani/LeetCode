class Solution {
public:

    void f(int i , int n, vector<string>&ans,string curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }

        for(char ch='a';ch<='c';ch++){
            if(curr.size()>0 && curr[i-1]==ch){
                continue;
            }
            f(i+1,n,ans,curr+ch);
        }
    }

    string getHappyString(int n, int k) {
        
        vector<string>ans;
        string curr="";
        f(0,n,ans,curr);
        if(ans.size()<k){
            return "";
        }

        return ans[k-1];

    }
};