class Solution {
public:
    
    bool check(string &word1,string &word2){
        int n=word1.size();
        int m=word2.size();
        if(word1.size()>word2.size()){
            return false;
        }
       for(int i=0;i<=m-n;i++){
        if(word2.substr(i,n)==word1){
            return true;
        }
       }
   return false;
    }



    vector<string> stringMatching(vector<string>& words) {
     
        int n=words.size();
        vector<string>ans;
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(check(words[i],words[j])==true  && words[i]!=words[j]){
                    st.insert(words[i]);
                }
            }
        }

        for(auto it:st){
            ans.push_back(it);
        }

        
        return ans;
    }
};