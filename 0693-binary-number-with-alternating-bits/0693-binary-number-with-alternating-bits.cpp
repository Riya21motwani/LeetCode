class Solution {
public:

    string func(int n){
        string ans="";
        while(n>0){
            int bit=n%2;
            ans.push_back('0' + bit);
            n=n/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    bool hasAlternatingBits(int n) {
        string bits=func(n);
        for(int i=1;i<bits.size();i++){
            if(bits[i]==bits[i-1]){
                return false;
            }
        }
            return true;
    }
};