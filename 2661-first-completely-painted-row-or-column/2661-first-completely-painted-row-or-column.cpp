class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int n1=arr.size();
        unordered_map<int,pair<int,int>>umap;

        //o(m*n)
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                umap[mat[i][j]] = {i, j};
            }
        }
        vector<int>drow(n);
        vector<int>dcol(m);
        for(int i=0;i<n1;i++){
           int row= umap[arr[i]].first;
           int col=umap[arr[i]].second;
           drow[row]++;
           dcol[col]++;

           if(drow[row]==m|| dcol[col]==n){
            return i;
           }
          
           
           
        }

        return -1;


    }
};