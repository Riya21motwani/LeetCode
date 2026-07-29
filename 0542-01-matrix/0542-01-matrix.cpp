class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,pair<int,int>>>q;
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                   ans[i][j]=0;
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
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 &&ncol>=0 && nrow<n && ncol<m && mat[nrow][ncol]==1 && 1+distance< ans[nrow][ncol]){
                    ans[nrow][ncol]=1+distance;
                    q.push({(1+distance),{nrow,ncol}});
                }
            }
        }

        return ans;
    }
};