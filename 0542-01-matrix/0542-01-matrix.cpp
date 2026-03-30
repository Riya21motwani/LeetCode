class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && mat[i][j]==0){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }

        
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        while(!q.empty()){
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();

            vis[row][col]=1;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && 1+ distance <ans[nrow][ncol]){           
                    ans[nrow][ncol]=1+distance;
                    q.push({1+distance, {nrow,ncol}});
                }
            }
        }

        return ans;
    }
};