class Solution {
public:
    
      bool findSafeWalk(vector<vector<int>>& grid, int health) {
    
    int n=grid.size();
        int m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>>qu;  //height : {row,col}
        vector<vector<int>>vis(n,vector<int>(m,0));
        if(grid[0][0]==1){
            qu.push({health-1,{0,0}});
        }
        else{
        qu.push({health,{0,0}});
        }
        vis[0][0]=1;
        
        while(!qu.empty()){
            int val=qu.top().first;
            int row=qu.top().second.first;
            int col=qu.top().second.second;

            if(row==n-1 && col==m-1){
                if(val>=1){
                    return true;
                }
            }

            qu.pop();
            int drow[4]={0,-1,0,1};
            int dcol[4]={-1,0,1,0};
            

            for(int i=0;i<4;i++){
                int n_row=row+drow[i];
                int n_col=col+dcol[i];
                if(n_row>=0 && n_row<n && n_col>=0 && n_col<m  &&  !vis[n_row][n_col] && grid[n_row][n_col]==0){
                    vis[n_row][n_col]=1;
                    qu.push({val,{n_row,n_col}});
                }
                else if (n_row>=0 && n_row<n && n_col>=0 && n_col<m  &&  !vis[n_row][n_col] && grid[n_row][n_col]!=0){
                    vis[n_row][n_col]=1;
                    qu.push({val-1,{n_row,n_col}});
                }
            }
        }

        return false;
    
//     typedef pair<int,int>p;
//     bool findSafeWalk(vector<vector<int>>& grid, int health) {
//          int n=grid.size();
//         int m=grid[0].size();
//         int drow[]={-1,0,1,0};
//         int dcol[]={0,1,0,-1};
//         priority_queue<pair<int,p>,vector<pair<int,p>>,greater<pair<int,p>>>pq;
//          vector<vector<int>>vis(n,vector<int>(m,0));
//         if(grid[0][0]==0){
//             pq.push({health, {0,0}});
//         }
//         else{
//             pq.push({health-1, {0,0}});
//         }
//         vis[0][0]=1;

//         while(!pq.empty()){
//             int health=pq.top().first;
//             int row=pq.top().second.first;
//             int col=pq.top().second.second;
           
//             pq.pop();

//              if(row==n-1 && col ==m-1 ){
//                 if(health>=1){
//                     return true;
//                 }
//              }
             
//              for(int i=0;i<4;i++){
//                 int nrow=row+drow[i];
//                 int ncol=col+dcol[i];
//                 if(nrow>=0 && ncol>=0 &&nrow<n &&ncol<m && health>0 && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
//                     vis[nrow][ncol]=1;
//                     pq.push({health-1, {nrow, ncol}});
//                 }
//                 else if(nrow>=0 && ncol>=0 &&nrow<n &&ncol<m  && health>0 && grid[nrow][ncol]==0 && vis[nrow][ncol]==0){
//                     vis[nrow][ncol]=1;
//                       pq.push({health, {nrow, ncol}});
//                 }
//              }
//         }
//           return false;
    }
};