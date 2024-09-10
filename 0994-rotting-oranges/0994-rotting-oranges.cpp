class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int n=grid.size();
          int m=grid[0].size();
            
          queue<pair<int,pair<int,int>>>q;
          int cnt1=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1){
                    cnt1++;
                }
            }
        }
        
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxi=0;
        while(!q.empty()){
            int row=q.front().second.first;
            int col=q.front().second.second;
            int t=q.front().first;
            maxi=max(maxi,t);
            
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                
                if(nrow>=0 &&ncol>=0 &&nrow<n &&ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    cnt++;
                    q.push({t+1,{nrow,ncol}});
                }
            }
            
             
        }
        if(cnt1!=cnt){
            return -1;
        }
         return maxi;
    }
};