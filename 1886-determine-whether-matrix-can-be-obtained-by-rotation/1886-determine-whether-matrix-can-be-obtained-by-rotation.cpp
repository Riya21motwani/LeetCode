class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int row=mat.size();
        int col=row;
        if(mat==target)return  true;
        int deg=3;
        while(deg--){
            
            for(int i=0;i<row;i++){
                for(int j=i;j<col;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<row;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat==target)return true;
        }
        return false;
    }
};