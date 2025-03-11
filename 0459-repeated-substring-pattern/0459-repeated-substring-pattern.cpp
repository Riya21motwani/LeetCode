class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();

        for(int i=1;i<=(n/2);i++){
            if(n%i==0){
                int cnt=n/i;
                string t=s.substr(0,i);
                string newstr="";
                while(cnt--){
                    newstr+=t;
                }
                if(newstr==s){
                    return true;
                }
            }
        }

        return false;
    }
};