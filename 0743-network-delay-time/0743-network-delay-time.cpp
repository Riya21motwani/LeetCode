class Solution {
public:
    typedef pair<int,int>p;
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(auto it : times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            adj[u].push_back({v,wt});
            
        }
        
        
        vector<int>dis(n+1,1e9);
        vector<int>vis(n+1,0);
        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int newnode=it.first;
                int newdistance=it.second;
                if(distance+newdistance<dis[newnode]){
                    dis[newnode]=distance+newdistance;
                    pq.push({distance+newdistance,newnode});
                }
            }
            
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e9){
                return -1;
            }
          maxi=max(maxi,dis[i]) ; 
        }
        return maxi;
    }
};