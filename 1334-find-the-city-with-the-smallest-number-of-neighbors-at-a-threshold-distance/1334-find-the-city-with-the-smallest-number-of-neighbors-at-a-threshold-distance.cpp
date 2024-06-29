class Solution {
public:
    typedef pair<int,int>p;
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
       	vector<vector<int>>adj[n];
        for(auto it: edges){
           adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int citycnt=1e9;
        int cityno=-1;
       for(int i=0;i<n;i++) {
        
        vector<int>dis(n,1e9);
        priority_queue<p,vector<p>,greater<p>>pq;
        pq.push({0,i});
           dis[i]=0;
        while(!pq.empty()){
             int node=pq.top().second;
             int distance=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int newnode=it[0];
                int newdistance=it[1];
                if(distance+newdistance<dis[newnode]){
                    dis[newnode]=newdistance+distance;
                    pq.push({newdistance+distance,newnode});
                }
            }
            
        }
           
           int cnt=0;
           for(int j=0;j<n;j++){
               if(dis[j]<= distanceThreshold){
                   cnt++;
               }
           }
        if(cnt<=citycnt){
            citycnt=cnt;
            cityno=i;
        }
       }
        return cityno;
    }
};