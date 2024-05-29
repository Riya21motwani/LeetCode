class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        string ans="";
        for(int i=0;i<n;i++){
              int j=i;
            while(j<n && j<i+9 && word[i]==word[j])j++;
            ans+=char(j-i+'0');
            ans+=word[i];
            i=j-1;
        }
        return ans;
    }
};