class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    isWater[i][j]=0;
                    vis[i][j]=1;
                    q.push({0,{i,j}});
                }
            }
        }

        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            isWater[row][col]=dis;

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 &&ncol>=0 && nrow<n &&ncol<m && isWater[nrow][ncol]==0 && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                    q.push({dis+1,{nrow,ncol}});
                }
            }

        }

        return isWater;


    }
};