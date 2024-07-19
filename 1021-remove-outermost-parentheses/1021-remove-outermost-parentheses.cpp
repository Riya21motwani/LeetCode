class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans="";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                cnt--;
            }
            if(cnt==1 && s[i]=='('){
                continue;
            }
            if(cnt==0 && s[i]==')'){
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};