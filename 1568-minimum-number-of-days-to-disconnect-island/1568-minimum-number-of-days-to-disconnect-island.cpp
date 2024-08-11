class Solution {
public:
    
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>&grid , int drow[], int dcol[]){
        vis[row][col]=1;
           int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=dcol[i]+col;
            if(nrow>=0 &&nrow<n && ncol>=0 && ncol <m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,grid, drow,dcol);
            }
        }
    }
    
    
    int noofisland(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        int drow[4]={-1,0,1,0};
        int cnt=0;
        int dcol[4]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                    
                    dfs(i,j, vis,grid , drow ,dcol);
                }
            }
        }
        return cnt;
    }
        
   

    
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=noofisland(grid);
        if(cnt>1 || cnt==0){
            return 0;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    grid[i][j]=0;
                    if(noofisland(grid) >1 || noofisland(grid)==0){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }
        
        return 2;
        
        
    }
};