class Solution {
public:

    typedef pair<int,int>p;
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<pair<int,p>,vector<pair<int,p>>,greater<pair<int,p>>>pq;
       
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        int maxi=-1;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        
    

         pq.push({0,{0,0}});
        if(grid[1][0]>1 && grid[0][1]>1){
            return -1;
        }
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int t=pq.top().first;
            pq.pop();
            if(vis[r][c]){
                continue;
            }
            vis[r][c]=true;
            if(r==n-1 && c==m-1){
                return t;
            }
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 &&ncol>=0 &&ncol<m && nrow<n  && vis[nrow][ncol]==false){
                    if(grid[nrow][ncol]<=t+1){
                     pq.push({t+1,{nrow,ncol}});
                    }else{
                        int diff=grid[nrow][ncol]-t;
                        if(diff%2==0){
                            pq.push({grid[nrow][ncol]+1,{nrow,ncol}});
                        }else{
                           pq.push({grid[nrow][ncol],{nrow,ncol}});
                        }
                    }
                    
                }
            }
        }
    
        return -1;
    }
};