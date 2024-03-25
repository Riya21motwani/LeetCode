class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int maxi=0;
        map<char,int>umap;
        int l=0;
        int r=0;

        for(int r=0;r<n;r++){
            if(umap.find(s[r])!=umap.end()){
                umap[s[r]]++;
                    while(umap[s[r]]>2){
                        umap[s[l]]--;
                        if(umap[s[l]]==0){
                            umap.erase(s[l]);
                        }
                        l++;
                    }
        
            }
            else{
                    umap[s[r]]++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};