class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(auto ch:s){
            if(isdigit(ch)){
                if(ans.size()>=1){
                    ans.pop_back();
                }
            }else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};