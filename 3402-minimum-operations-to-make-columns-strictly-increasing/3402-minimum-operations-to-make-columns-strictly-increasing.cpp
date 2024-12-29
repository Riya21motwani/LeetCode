class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[j-1][i]>=grid[j][i]){
                    int maxi=max(grid[j-1][i],grid[j][i]);
                    int val=maxi-grid[j][i];
                    if(val<0){
                        continue;
                    }
                    cnt+=val+1;
                    grid[j][i]=maxi+1;
                }
            }
        }
        return cnt;
    }
};