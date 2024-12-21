class Solution {
public:
    long long  dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&values,int &no_of_components,int k){
        vis[node]=1;
        long long  x=0;
        bool loop=false;
        for(auto i:adj[node]){
            if(!vis[i]){
                long long a=dfs(i,adj,vis,values,no_of_components,k);
                loop=true;
                
                if(a%k==0){no_of_components++;}
                else{x+=a;}
            }
        }
        if(loop){return x+values[node];}
        return values[node];
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
         vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
           
        }
        vector<int>vis(n,0);
        int no_of_components=1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int sum=dfs(i,adj,vis,values,no_of_components,k);//O(Edges)
                
            }
        }
        return no_of_components;
        
        
    }
};