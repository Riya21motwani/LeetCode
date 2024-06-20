class Solution {
public:
    
    void bfs(int row,int col, vector<vector<char>>&vis ,  vector<vector<char>>&grid ){
         int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
       while(!q.empty()){
           int row=q.front().first;
           int col=q.front().second;
           q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
           for(int i=0;i<4;i++){
               int nrow=row+drow[i];
               int ncol=col+dcol[i];
               if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
                   bfs(nrow,ncol,vis,grid);
               }
           }
           
       }
        
        
       
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<char>>vis(n,vector<char>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                  if(!vis[i][j] && grid[i][j]=='1'){
                      bfs(i,j,vis,grid);
                      cnt++;
                  }
            }
        return cnt;
    }
};