class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        int cnt=1;
        int i=0;
        int j=i+1;
        while(j<n){
            while(word[i]==word[j]){
                 cnt++;
                 j++;
            }
            if(word[i]!=word[j]){
                i=j;
                j++;
            }
        }

        return cnt;
    }
};