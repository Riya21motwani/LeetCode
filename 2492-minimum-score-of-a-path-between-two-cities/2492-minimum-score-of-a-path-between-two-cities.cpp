class Solution {
public:

    void dfs(int node,  unordered_map<int,vector<pair<int,int>>>&adj ,  vector<bool>&vis , int n, int &res ){
        vis[node]=true;

        for(auto it:adj[node]){
            res=min(res,it.second);
            if(!vis[it.first]){
                dfs(it.first,adj,vis,n,res);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;

        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<bool>vis(n,false);

        dfs(1,adj,vis,n,res);


        return res;
    }
};