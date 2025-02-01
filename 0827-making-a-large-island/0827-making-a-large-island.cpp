class Solution {
public:
    int dfs(int i, int j ,vector<vector<int>>& grid,vector<vector<int>>& vis , int id){
        int n=grid.size();
        if(i<0 || j<0 || i>=n || j>=n || vis[i][j]==1 || grid[i][j]==0){
            return 0;
        }
        int cnt=1;
        vis[i][j]=1;
        grid[i][j]=id;
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];
            cnt+=dfs(nrow,ncol,grid,vis, id);
        }
        return cnt;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_map<int,int>umap;
        int maxi=0;
         int drow[]={-1,1,0,0};
        int dcol[]={0,0,-1,1};
        int id=2;
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                if(grid[i][j]==1 && !vis[i][j]){
                    int size=dfs(i,j,grid,vis,id);
                    umap[id]=size;
                    id++;
                    maxi=max(maxi,size);

                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                unordered_set<int>uset;
                int sum=0;
                if(grid[i][j]==0){
                    
                    for(int k=0;k<4;k++){
                        int nrow=i+drow[k];
                        int ncol=j+dcol[k];
                        if(nrow<n && ncol<n &&nrow>=0 &&ncol>=0 && grid[nrow][ncol]>1){
                            uset.insert(grid[nrow][ncol]);
                        }
                    }
                }
                for(auto it:uset){
                    sum+=umap[it];
                }
                maxi=max(maxi,sum+1);

            }
        }

return maxi;
    }
};
