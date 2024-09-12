class Solution {
public:
    typedef pair<int,int>p;
    int countPaths(int n, vector<vector<int>>& roads) {
      
        
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

      
        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector<long long> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

       
        int mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            long long distance=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                long long newdistance=it.second;
                long long newnode=it.first;
                
                if(distance +newdistance < dist[newnode]){
                    dist[newnode]=distance +newdistance;
                    ways[newnode]=ways[node];
                    pq.push({distance +newdistance, newnode});
                }
                else if(distance +newdistance == dist[newnode]){
                    ways[newnode]=(ways[newnode]+ways[node])%mod;
                }
                
                
                
            }
        }
        return ways[n-1]%mod;

    }
};