class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string temp;
        int i=0;
        int j=0;
        int n=s.size();
        for(auto ch:s){
            temp.push_back(ch);
            if(temp.size()==k){
                ans.push_back(temp);
                temp.clear();
            }

        }
        if(temp.size()==0){
            return ans;
        }
        while(temp.size()<k){
            temp.push_back(fill);

        }
        ans.push_back(temp);
        return ans;
    }
};