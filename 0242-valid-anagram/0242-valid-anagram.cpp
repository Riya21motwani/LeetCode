class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<int,int>umap1;
        unordered_map<int,int>umap2;
        for(auto it:s){
            umap1[it]++;
        }
        for(auto it:t){
            umap2[it]++;
        }
        for(int i=0;i<s.size();i++){
          
               if(umap2[s[i]]!=umap1[s[i]]){
                   return false;
               
           }
        }
        return true;
    }
};