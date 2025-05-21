class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxilen=0;
        int maxf=0;
        vector<int>umap(26,0);
        while(r<n){
            umap[s[r]-'A']++;
            maxf=max(maxf,umap[s[r]-'A']);
            if((r-l+1)-maxf >k){
                umap[s[l]-'A']--;

                l++;
            }
            if((r-l+1) -maxf <=k){
                maxilen=max(maxilen,r-l+1);
            }
            r++;
        }

        return maxilen;
    }
};