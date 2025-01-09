class Solution {
public:

    bool check(string &word,string &pref){
        if(word.size()<pref.size()){
            return false;
        }

        return word.substr(0,pref.size())==pref;
    }

    int prefixCount(vector<string>& words, string pref) {
        int n=words.size();
        int cnt=0;

        for(int i=0;i<n;i++){
            if(check(words[i],pref)){
                cnt+=1;
            }
        }

        return cnt;
    }
};