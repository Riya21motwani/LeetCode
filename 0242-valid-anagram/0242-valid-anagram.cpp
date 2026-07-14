class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<int,int>umap;
        if(n!=m)return false;
        for(int i=0;i<n;i++){
            umap[s[i]]++;
        }
        for(int j=0;j<m;j++){
            if(umap.find(t[j])!=umap.end()){
                umap[t[j]]--;
                if(umap[t[j]]==0){
                    umap.erase(t[j]);
                }
            }
            else{
                return false;
            }
        }

        return true;
    }
};