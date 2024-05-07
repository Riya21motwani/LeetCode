class Solution {
public:
    int n,m;
    int ans;
    int nonob;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void backtrack(vector<vector<int>>& grid,int cnt,int i,int j){

    if(i<0 || j<0 ||i>=m||j>=n|| grid[i][j]==-1){
          return;
    }
        if(grid[i][j]==2){
              if(cnt==nonob){
                    ans+=1;
              }
            return;
        }
        
        grid[i][j]=-1;
        
        for(vector<int> &d:directions){
              int newx=i+d[0];
              int newy=j+d[1];
            backtrack(grid,cnt+1,newx,newy);
        }
        
        
        
        grid[i][j]=0;
    
    
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        nonob=0;
        ans=0;
        
        int startx=0;
        int starty=0;
        for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                   if(grid[i][j]==0){
                    nonob++;
                   }
                 if(grid[i][j]==1){
                     startx=i;
                     starty=j;
                 }
             }

        }
        
        nonob+=1;
        backtrack(grid,0,startx,starty);
        
        return ans;
        
        
        
    }
};