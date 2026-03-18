class Solution {
public:





    void dfs(int node, vector<int>&vis, unordered_map<int,vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }

        int n=isConnected.size();
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                if(vis[it]==0){
                    
                    vis[it]=1;
                    dfs(it,vis,adj);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};