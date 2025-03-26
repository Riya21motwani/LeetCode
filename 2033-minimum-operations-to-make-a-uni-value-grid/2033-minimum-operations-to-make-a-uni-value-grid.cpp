class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        int size=m*n;
        vector<int>mat;

        if(grid.size()==1 && grid[0].size()==1){
            return 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               mat.push_back(grid[i][j]);
            }
        }

        sort(mat.begin(),mat.end());
        int mid=size/2;
        int val=mat[mid];
        int cnt=0;
        for(int i=0;i<size;i++){
            if(mat[i]%x!=0){
                return -1;
            }else{

            
            int t=(abs(mat[i]-val));
            cnt+=(t/x);

            }
        }

        return cnt;

    }
};