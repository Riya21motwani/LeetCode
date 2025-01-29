class Solution {
private:
   
    int countFishes(vector<vector<int>>& grid,
                    int row, int col, int &sum, int &maxi) {
        int n=grid.size();
        int m=grid[0].size();
        if(row<0 || col<0 || col>=m || row>=n|| grid[row][col]==0){
            return 0;
        }
        sum+=grid[row][col];
        grid[row][col]=0;
        maxi=max(maxi,sum);
        


      
        int drow[] = {0, 0, 1, -1};
        int dcol[]= {1, -1, 0, 0};

        for(int i=0;i<4;i++){
            int nrow=drow[i]+row;
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]>0){
                
                
                countFishes(grid,nrow,ncol,sum,maxi);
            }
        }
      
        return maxi;
    }

public:
   
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size(), numCols = grid[0].size(), result = 0;
        vector<vector<bool>> visited(numRows, vector<bool>(numCols));

       
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                int sum=0;
                int maxi=0;
                if (grid[i][j]>0) {
                    result = max(result, countFishes(grid, i, j,sum,maxi));
                }
            }
        }
        return result;
    }
};