class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int n1=arr.size();
       unordered_map<int,int>umap;

       for(int i=0;i<n1;i++){
        umap[arr[i]]=i;
       }

       vector<int>row(n,-1);
       vector<int>col(m,-1);

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int idx=umap[mat[i][j]];
            row[i]=max(row[i],idx);
            col[j]=max(col[j],idx);
        }
       }

        int mini=INT_MAX;

       for(int i=0;i<n;i++){
        mini=min(mini,row[i]);
       }
       for(int i=0;i<m;i++){
        mini=min(mini,col[i]);
       }


        return mini;
    }
};