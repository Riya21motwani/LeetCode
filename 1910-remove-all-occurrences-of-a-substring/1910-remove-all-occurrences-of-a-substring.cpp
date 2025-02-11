class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string ans="";

        for(int i=0;i<n;i++){
            ans.push_back(s[i]);
            if(ans.size()>=m){
                if(ans.substr(ans.size()-m)==part){
                    ans.erase(ans.size()-m);
                }
            }
            
        }

        return ans;
    }
};