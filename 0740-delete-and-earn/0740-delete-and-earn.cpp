class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        vector<int>newa;
        for(auto it:umap){
            newa.push_back(it.first);
        }
         sort(newa.begin(),newa.end());
        int m= newa.size();

        vector<int>dp(m+1,0);
        dp[0]=newa[0]*umap[newa[0]];

        if(m==1)return dp[0];
        
        if(newa[1]==newa[0]+1){
            dp[1]=max(newa[1]*umap[newa[1]],dp[0]);
        }else{
            dp[1]=dp[0]+newa[1]*umap[newa[1]];
        }

        for(int i=2;i<m;i++){
            int earn=umap[newa[i]]*newa[i];
            if(newa[i]==newa[i-1]+1){
                dp[i]=max(dp[i-2]+earn,dp[i-1]);
            }else{
                dp[i]=earn+dp[i-1];
            }
            
        }
        
       

        return dp[m-1];
        
    }
};