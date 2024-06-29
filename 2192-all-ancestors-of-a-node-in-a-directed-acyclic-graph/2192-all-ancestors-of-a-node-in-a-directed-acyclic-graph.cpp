class Solution {
public:
    
    void dfs(int node, vector<vector<int>>&adj, unordered_set<int>&uset ){
       uset.insert(node);
        for(auto it:adj[node]){
            if(uset.find(it)==uset.end()){
                dfs(it,adj,uset);
            }
        }
        
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<vector<int>> ans;
        int m=edges.size();
      
            for(auto it:edges){
                int u=it[0];
                int v=it[1];
                adj[v].push_back(u);
            }
        
            for(int i=0;i<n;i++){
               unordered_set<int>uset;
                vector<int>ls;
                dfs(i,adj,uset);
                for(int j=0;j<n;j++){
                    if(j==i)continue;
                    if(uset.find(j)!=uset.end()){
                        ls.push_back(j);
                    }
                }
                
                ans.push_back(ls);
            }
         return ans;
        
       
    }
};