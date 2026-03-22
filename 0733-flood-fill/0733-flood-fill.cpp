class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ori=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        q.push({sr,sc});
        vis[sr][sc]=1;
        image[sr][sc]=color;
         int drow[]={-1,1,0,0};
            int dcol[]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
           
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && image[nrow][ncol]==ori){
                    q.push({nrow,ncol});
                    image[nrow][ncol]=color;
                     vis[nrow][ncol]=1;
                }
            }
        }

        return image;
    }
};