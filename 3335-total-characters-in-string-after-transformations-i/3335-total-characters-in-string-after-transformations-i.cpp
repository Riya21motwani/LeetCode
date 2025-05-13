class Solution {
public:

    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
       
        vector<int>umap(26,0);
        for (char c : s) {
            umap[c-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<int>d(26,0);
            for(int j=0;j<26;j++){
                char ch=j+'a';
                int cnt=umap[j];
                if(ch=='z'){
                    d[0]=(d[0]+cnt)%mod;
                    d[1]=(d[1]+cnt)%mod;
                }
                else{
                    d[ch+1-'a']=(d[ch+1-'a']+cnt)%mod;
                }

            }
            umap=d;
        }

        int countofchar=0;
        for(int i=0;i<26;i++){
            countofchar=(countofchar+umap[i])%mod;
        }

        return countofchar;


        
    }
};