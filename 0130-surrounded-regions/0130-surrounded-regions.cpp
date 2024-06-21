class Solution {
public:
    
    void dfs(int row ,int col, vector<vector<char>>& board  , vector<vector<int>>&vis ,int drow[],int dcol[]){
        vis[row][col]=1;
         int n=board.size();
        int m=board[0].size();
      
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis,drow,dcol);
            }
        }
    }
      
    
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
          int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,board,vis,drow,dcol);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,board,vis,drow,dcol);
            }
        }
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,board,vis,drow,dcol);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,board,vis,drow,dcol);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};






