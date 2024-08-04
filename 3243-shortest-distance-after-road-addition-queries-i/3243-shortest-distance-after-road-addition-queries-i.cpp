class Solution {
public:
  typedef pair<int,int>p;
    int findshortest( unordered_map<int,vector<int>>&adj , int n){
       queue<int>q;
        vector<int>dis(n,1e9);
        q.push(0);
        dis[0]=0;
        while(!q.empty()){
            int node=q.front();
            
            q.pop();
            for(auto it : adj[node]){
                if(dis[node]+1 < dis[it]){
                    dis[it]=dis[node]+1;
                    q.push(it);
                }
            }
        }
        return dis[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
       unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);

        }
          vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0];
            int v=queries[i][1];
            adj[u].push_back(v);
            int shortestdistance =findshortest(adj,n );
                ans[i]=shortestdistance;
        }
        return ans;
    }
};