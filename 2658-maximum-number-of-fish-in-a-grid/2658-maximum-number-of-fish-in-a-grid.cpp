class Solution {
public:
   
    int bfs(vector<vector<int>>& grid,int i, int j) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;

        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            sum+=grid[row][col];
            grid[row][col]=0;

            for(int k=0;k<4;k++){
                int nrow=row+drow[k];
                int ncol=col+dcol[k];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]>0){
                    q.push({nrow,ncol});
                }
            }


        }

        return sum;

    }


    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols));

       
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int sum=0;
                int maxi=0;
                if (grid[i][j]>0) {
                    result = max(result, bfs(grid, i, j));
                }
            }
        }
        return result;
    }
};