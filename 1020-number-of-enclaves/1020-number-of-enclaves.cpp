class Solution {
public:
    
    
    void dfs( int row , int col,  vector<vector<int>>& grid, vector<vector<int>>&vis, int drow[],  int dcol[]){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,vis,drow,dcol);
            }
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
          int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
         for(int j=0;j<m;j++){
            if(grid[0][j]==1 && vis[0][j]==0){
                dfs(0,j,grid,vis,drow,dcol);
            }
            if(grid[n-1][j]==1 && vis[n-1][j]==0){
                dfs(n-1,j,grid,vis,drow,dcol);
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0,grid,vis,drow,dcol);
            }
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1,grid,vis,drow,dcol);
            }
        }
       
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(grid[i][j]==1 && vis[i][j]==0){
                       cnt++;
                   }
            }
        }
        return cnt;
    }
};

