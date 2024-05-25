class Solution {
public:
    vector<string>result;
    
    void solve(int i, string &currsentence, unordered_set<string>&st, string & s){
          if(i>=s.size()){
            result.push_back(currsentence);
              return;
          }
        
        for(int j=i;j<s.size();j++){

             string tempword=s.substr(i,j-i+1);
            
            if(st.find(tempword)!=st.end()){
                string orisentence=currsentence;
                if(!currsentence.empty()){
                 currsentence+=" ";
                }
                currsentence+=tempword;
                solve(j+1,currsentence,st,s);
                currsentence=orisentence;
            
            }
            
        }
        
        
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(string &word : wordDict){
            st.insert(word);
        }
        string currsentence="";
        solve(0,currsentence,st ,s);
        return result;
    }
};