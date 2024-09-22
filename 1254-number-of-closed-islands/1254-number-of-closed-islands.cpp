class Solution {
public:
   
    bool dfs(int i,int j, vector<vector<int>>& grid, int n, int m){
        
        if(i>=n || i<0 || j>=m || j<0){
            return false;
        }
        if(grid[i][j]==1){
            return true;
        }
        grid[i][j]=1;
        
        bool left=dfs(i,j-1,grid,n,m);
        bool right=dfs(i,j+1,grid,n,m);
        bool up=dfs(i-1,j,grid,n,m);
        bool down=dfs(i+1,j,grid,n,m);
        
        return left&& right && up && down;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    if(dfs(i,j,grid,n,m)==true){
                        cnt++;
                    }
                }
            }
        }
       return cnt;
    }
};