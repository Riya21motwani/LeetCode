class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        int ans=0;
        unordered_map<char,int>umap;
        int i=0;
       
       for(int j=0;j<n;j++){
        umap[s[j]]++;
        
        while(umap.size()==3){
            ans+=(n-j);
            umap[s[i]]--;
            if(umap[s[i]]==0){
                umap.erase(s[i]);
            }
            i++;
        }

       }
       
       
       return ans;
    }
};