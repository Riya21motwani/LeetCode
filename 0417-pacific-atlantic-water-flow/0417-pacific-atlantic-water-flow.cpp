class Solution {
public:

    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&heights){
        vis[row][col]=1;
         int n=heights.size();
        int m=heights[0].size();
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 &&nrow<n &&ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol]>=heights[row][col]){
                dfs(nrow,ncol,vis,heights);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacvis(n,vector<int>(m,0));
        vector<vector<int>>atvis(n,vector<int>(m,0));
        vector<vector<int>>ans;

        for(int j=0;j<m;j++){
            if(!pacvis[0][j]){
            dfs(0,j,pacvis, heights);
            }
            if(!atvis[n-1][j]){
                dfs(n-1,j,atvis,heights);
            }
            
        }
        for(int i=0;i<n;i++){
            if(!pacvis[i][0]){
            dfs(i,0,pacvis, heights);
            }
            if(!atvis[i][m-1]){
                dfs(i,m-1,atvis,heights);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacvis[i][j]==1 && atvis[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};