class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
    int n=grid.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                q.push({i,j});

            }
        }
    }
    int drow[]={-1,1,0,0};
    int dcol[]={0,0,1,-1};
    int cnt=-1;
    while(!q.empty()){
        int size=q.size();
        cnt++;
        for(int i=0;i<size;i++){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
    
        for(int i=0;i<4;i++){
            int nrow=drow[i]+r;
            int ncol=dcol[i]+c;
            if(nrow>=0 && ncol>=0 &&nrow<n &&ncol<n && grid[nrow][ncol]==0){
                q.push({nrow,ncol});
                grid[nrow][ncol]=1;
                
            }
        }
        }

    }
return cnt;

    }
};