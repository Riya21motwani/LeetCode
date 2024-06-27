class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        
        int m=flights.size();
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
           adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,1e9);
        dis[src]=0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stop=q.front().first;
            int node=q.front().second.first;
            int distance=q.front().second.second;
            q.pop();
            // if(stop>k)continue;
            for(auto it:adj[node]){
                int newnode=it.first;
                int newdistance=it.second;
                if(newdistance+distance<dis[newnode] && stop<=k){
                    dis[newnode]=newdistance+distance;
                    q.push({stop+1,{newnode,newdistance+distance}});
                }
            }
            
            
        }
        
        
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};