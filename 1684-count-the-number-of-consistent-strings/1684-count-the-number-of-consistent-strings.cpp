class Solution {
public:
    
    bool check(string s ,  unordered_set<char>&uset){
        for(int i=0;i<s.size();i++){
            if(uset.find(s[i])==uset.end()){
                return false;
            }
        }
        return true;
    }
    
    
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>uset;
        for(int i=0;i<allowed.size();i++){
            uset.insert(allowed[i]);
        }
        int cnt=0;
        for(int i=0;i<words.size();i++){
            if(check(words[i],uset)){
                cnt++;
            }
        }
        return cnt;
    }
};