class Solution {
public:
    
    int f(int j, int k, unordered_map<int,int>&umap,vector<int>&arr, vector<vector<int>>&dp){
        if(j<0){
            return 0;
        }
        if(dp[j][k]!=-1){
            return dp[j][k];
        }
        int val=arr[k]-arr[j];
        if(umap.find(val)!=umap.end() && umap[val]<j){
            return dp[j][k]= 1+ f(umap[val],j,umap,arr,dp);
        }
        return dp[j][k]=2;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; 
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxlen=0;
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[arr[i]]=i;
        }
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=f(j,k,umap,arr,dp);
                if(len>=3){
                    maxlen=max(maxlen,len);
                }
            }
        }
       
       return maxlen;
    }
};
