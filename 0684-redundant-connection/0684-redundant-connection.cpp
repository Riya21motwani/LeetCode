class Solution {
    
public:

    bool alreadyconnected(int u, int v, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
        
        if(u==v){
            return true;
        }
        visited[u]=true;
        for(auto it:adj[u]){
            if(!visited[it]){
                alreadyconnected(it,v,adj,visited);
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        int m=edges[0].size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           adj[u].push_back(v);
           adj[v].push_back(u);
        }

        vector<int>vis(n+1,0);
        vector<int>ans;

        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(vis[u]==true && vis[v]==true){
                vector<bool>visited(n+1,false);
                if(alreadyconnected(u,v,adj,visited)==false){
                    
                    ans.push_back(u);
                     ans.push_back(v);
                     break;
                }
            }
           else {

            if(vis[u]==false){
                vis[u]=true;
            }
            if(vis[v]==false){
                vis[v]=true;
            }
           }
             
            
        }

        return ans;
    }
};