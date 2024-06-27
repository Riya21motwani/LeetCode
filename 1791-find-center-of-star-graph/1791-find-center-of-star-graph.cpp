class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
       unordered_map<int,int>umap;
        
        for(auto it:edges){
             umap[it[0]]++;
            umap[it[1]]++;
        }
        
        for(auto it:umap){
            if(it.second==n){
                return it.first;
            }
        }
        return -1;
    }
};