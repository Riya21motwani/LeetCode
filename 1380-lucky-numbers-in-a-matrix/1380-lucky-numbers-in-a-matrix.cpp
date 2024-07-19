class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>v1;
        vector<int>v2;
        unordered_map<int,int>umap2;
        for(int i=0;i<n;i++){
            int minirow=INT_MAX;
            for(int j=0;j<m;j++){
                minirow=min(minirow,matrix[i][j]);
            }
            v1.push_back(minirow);
        }
        
        
        for(int j=0;j<m;j++){
            int maxcol=INT_MIN;
            for(int i=0;i<n;i++){
                maxcol=max(maxcol,matrix[i][j]);
            }
           v2.push_back(maxcol);
        }
        vector<int> ans;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]==v1[i] && matrix[i][j]==v2[j]){
                    ans.push_back(v1[i]);
               }
           }
       }
       return ans;
        
    }
};