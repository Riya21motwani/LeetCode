class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string ans="";
        int i=0;
        while(i<n){
            if(s[i]>='A'&& s[i]<='Z'){
                ans+=tolower(s[i]);
            }else if(s[i]>='a' && s[i]<='z'  || isdigit(s[i])){
                ans+=s[i];
            }
            i++;
        }

         i=0;
        int j=ans.size()-1;

        while(i<=j){
            if(ans[i]!=ans[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }

        return true;
    }
};