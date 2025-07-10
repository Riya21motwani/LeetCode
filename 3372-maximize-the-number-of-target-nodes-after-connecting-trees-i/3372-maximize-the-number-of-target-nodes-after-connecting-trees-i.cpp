class Solution {
public:

     int bfs(int node,   unordered_map<int,vector<int>>&adj , int k , vector<int>&vis){
        int cnt=0;
        queue<pair<int,int>>q;
        q.push({node,0});

        

        while(!q.empty()){
            int newnode=q.front().first;
            int dist=q.front().second;
            q.pop();
            vis[newnode]=1;
            if(dist>k){
                continue;
            }
            cnt++;
            for(auto it:adj[newnode]){
                if(!vis[it]){
                    q.push({it,dist+1});
                }
            }
        }
        return cnt;
    }

    vector<int>f( vector<vector<int>>& edges , int k){
        int n=edges.size();
        vector<int>res(n+1,1);
        
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<=n;i++){
            
            vector<int>vis(n+1,0);
                res[i]=bfs(i,adj,k,vis);
            
        }
        return res;
    
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int>a1=f(edges1,k);
        vector<int>a2=f(edges2,k-1);
        int maxicnt=*max_element(a2.begin(),a2.end());
        
        for(int i=0;i<a1.size();i++){
            a1[i]+=maxicnt;

        }
        return a1;
    }
};