class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;int j=0;
        int maxlen=0;
        int maxfreq=0;
        int map[26]={0};
        while(j<n){
            
            map[s[j]-'A']++;
            maxfreq=max(maxfreq, map[s[j]-'A']);
            while(j-i+1 - maxfreq >k){
               map[s[i]-'A']--;
                for(int p=0;p<26;p++){
                    maxfreq=max(maxfreq,map[p]);
                }
                i++;
            }
            if(j-i+1 - maxfreq <=k){
                maxlen=max(maxlen , j-i+1);
            }
            
            j++;
        }
        return maxlen;
    }
};