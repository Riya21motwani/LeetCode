class Solution {
public:
    void solve(vector<vector<char>>& board) {
       
       int n =board.size();
       int m=board[0].size();

       vector<vector<int>>dist(n,vector<int>(m,0));

       queue<pair<int,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((j==0 || j==m-1 || i==0 || i==n-1) && board[i][j]=='O'){
                dist[i][j]=-1;
                q.push({i,j});
            }
        }
       }
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && ncol<m && nrow<n && dist[nrow][ncol]==0 &&  board[nrow][ncol]=='O'){
                    dist[nrow][ncol]=-1;
                    
                    q.push({nrow,ncol});
                }
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && dist[i][j]==0){
                    board[i][j]='X';
                }
            }
        }



       
    }
};