class Solution {
public:
    typedef pair<int,int>p;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
       vector<int>adj[n+1];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>d1(n+1,1e9);
        vector<int>d2(n+1,1e9);
        
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,1});
        d1[1]=0;
        while(!pq.empty()){
            int timepass=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==n && d2[n]!=1e9){
                return d2[n];
            }
           
            int d=timepass/change;
            
            if(d%2==1){
                timepass=(d+1)*change;
                
            }
            
            for(auto it:adj[node]){
                if(d1[it]>timepass+time){
                    d2[it]=d1[it];
                    d1[it]=timepass+time;
                    pq.push({timepass+time,it});
                }
                else if(d2[it]>timepass+time && d1[it]!=timepass+time){
                    d2[it]=timepass+time;
                    pq.push({timepass+time,it});
                }
            }
            
            
        }
        
        
        return -1;
        
        
    }
};