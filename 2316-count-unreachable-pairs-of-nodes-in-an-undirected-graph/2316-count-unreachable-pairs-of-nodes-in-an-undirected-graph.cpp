class Solution {
public:

    void dfs(int i , vector<long long>&vis ,unordered_map<long long,vector<long long>>&adj , long long &cnt ){
        vis[i]=1;
        cnt++;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,  vis, adj , cnt);
            }
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        unordered_map<long long,vector<long long>>adj;
        for(auto it:edges){
            long long u=it[0];
            long long v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long>vis(n,0);
        long long curr=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            long long cnt=0;
            dfs(i,vis,adj,cnt);
            ans+=(cnt*(curr-cnt));
            curr=curr-cnt;
            }
        }
        
        return ans;
    }
};