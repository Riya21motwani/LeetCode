class Solution {
    
public:

    bool alreadyconnected(int u, int v, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        
        if(u==v){
            return true;
        }
        visited[u]=true;
        for(auto it:adj[u]){
            if(!visited[it]){
                if(alreadyconnected(it,v,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int m=edges[0].size();
        unordered_map<int,vector<int>>adj;
        vector<int>ans;

        for(int i=0;i<n;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           vector<bool>visited(n+1,false);
           if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && alreadyconnected(u,v,adj,visited)){
            return edges[i];
           }
           adj[u].push_back(v);
           adj[v].push_back(u);

        }

        

       

        return {};
    }
};