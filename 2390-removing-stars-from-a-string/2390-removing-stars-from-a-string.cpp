class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
       string ans="";
       for(int i=0;i<n;i++){
        if(s[i]!='*'){
            ans.push_back(s[i]);
        }else if( ans.size()>0 && s[i]=='*'){
            ans.pop_back();
        }
       }
       return ans;
    }
};