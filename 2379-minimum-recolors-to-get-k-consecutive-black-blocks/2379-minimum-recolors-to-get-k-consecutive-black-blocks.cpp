class Solution {
public:

    int f(string s){
        int cntw=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='W'){
                cntw++;
            }
        }
        return cntw;
    }


    int minimumRecolors(string blocks, int k) {

        int mini=INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            int cnt=f(blocks.substr(i,k));
            mini=min(mini,cnt);
        }
        return mini;
    }
};