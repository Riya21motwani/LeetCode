class Solution {
public:
    
    void dfs( int row, int col,vector<vector<int>>&ans,vector<vector<int>>& image,int color, int drow[], int dcol[],  int initial_color){
        ans[row][col]=color;
        
        int n=image.size();
        int m=image[0].size();
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n&& ncol>=0 && ncol<m && image[nrow][ncol]==initial_color && ans[nrow][ncol]!=color){
                dfs(nrow,ncol,ans,image,color,drow,dcol,initial_color);
            }
        }
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int initial_color= image[sr][sc];
       
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,color,drow,dcol,initial_color);
        return ans;
    }
};