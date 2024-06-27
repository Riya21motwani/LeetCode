class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        vector<vector<int>>dis(n,vector<int>(n,1e9));
       queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        dis[0][0]=1;
        vector<pair<int,int>> dir={{0,1},{0,-1},{-1,0},{1,0},{1,1},{1,-1},{-1,1},{-1,-1}}; 
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            for(auto it:dir){
                int nrow=row+it.first;
                int ncol=col+it.second;
                if(nrow>=0 &&ncol>=0 &&nrow<n&& ncol<n && grid[nrow][ncol]==0 &&  1+distance<dis[nrow][ncol]){
                    dis[nrow][ncol]=1+distance;
                    q.push({1+distance,{nrow,ncol}});
                }
            }
        }
        if(dis[n-1][n-1]==1e9)return -1;
            return dis[n-1][n-1];
    }
};