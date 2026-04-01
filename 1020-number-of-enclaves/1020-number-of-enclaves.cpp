class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int cnt1=0;
        int cnt=0;
        int n=grid.size();
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    cnt1++;
                }
                if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;

                }
                
            }
        }


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            cnt++;

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({nrow,ncol});
                }
            }

        }

        
        return cnt1-cnt;
    }
};