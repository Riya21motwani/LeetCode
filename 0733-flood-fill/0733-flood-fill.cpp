class Solution {
public:
    
//     
    int n, m;
    
    void dfs( vector<vector<int>>& image, int sr, int sc, int color , int initialcolor ,  vector<vector<int>>&ans , int drow[],int dcol[]){
        ans[sr][sc]=color;
        
        for(int i=0;i<4;i++){
            int nrow=drow[i]+sr;
            int ncol=dcol[i]+sc;
            if(nrow>=0 && ncol>=0 && nrow<n && ncol< m && image[nrow][ncol]==initialcolor && ans[nrow][ncol] !=color){
                
                dfs(image, nrow,ncol , color, initialcolor,ans, drow,dcol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         vector<vector<int>>ans=image;
        n=image.size();
        m=image[0].size();
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int initialcolor=image[sr][sc];
    
       dfs(image,sr,sc,color,initialcolor, ans , drow, dcol);
            
            return ans;
    }
};