class Solution {
public:
    
    void dfs(int ancestor, int currnode ,  unordered_map<int,vector<int>>&adj, vector<vector<int>>& ans ){
         
        for(auto it:adj[currnode]){
            if(ans[it].empty() || ans[it].back()!=ancestor){
            ans[it].push_back(ancestor);
            dfs(ancestor, it,adj,ans);
        }
    }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<vector<int>> ans(n);
        int m=edges.size();
      
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                adj[u].push_back(v);
            }
        
            for(int i=0;i<n;i++){
                int ancestor=i;
                dfs(ancestor, i ,adj ,ans);
            }
        
       return ans;
    }
};