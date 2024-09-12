class Solution {
public:
    typedef pair<int,int>p;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        dis[0][0]=1;
     queue<pair<int,pair<int,int>>>pq;
        
        
        vector<pair<int,int>>dir={{-1,1},{1,1} ,{1,-1}, {-1,-1} , {0,1} , {1,0} , {-1,0} , {0,-1}};
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int distance=pq.front().first;
            int row=pq.front().second.first;
            int col=pq.front().second.second;
            pq.pop();
            if(row==n-1 &&col==n-1){
                return distance;
            }
            for(auto it:dir){
              int nrow=it.first+row;
                int ncol=it.second+col;
                if(nrow>=0 &&ncol>=0 &&ncol<n &&nrow<n && 1+distance < dis[nrow][ncol] && grid[nrow][ncol]==0 ){
                    dis[nrow][ncol]=1+distance;
                    pq.push({1+distance, {nrow,ncol}});
                }
            }
            
        }
        
         if(dis[n-1][n-1]==1e9)return -1;
            return dis[n-1][n-1];
    }
};