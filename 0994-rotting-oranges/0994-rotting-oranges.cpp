class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                    
                }
                if(grid[i][j]==1){
                    cnt1++;
                }
            }
        }
        int cnt=0;
        int maxi=0;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};

        while(!q.empty()){
            int time=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            maxi=max(maxi,time);
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({time+1,{nrow,ncol}});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
            }

        }

        if(cnt1!=cnt){
            return -1;
        }

        return maxi;
    }

};