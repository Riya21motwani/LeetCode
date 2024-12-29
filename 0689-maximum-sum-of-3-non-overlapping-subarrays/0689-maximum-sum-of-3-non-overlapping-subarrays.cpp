class Solution {
public:

    int find(int i,int cnt, vector<int>& sub, int k, int n , vector<vector<int>>&dp){

        

        
         if(cnt==0){
            return 0;
        }
        if(i>=n){
            return INT_MIN;
        }
        
        if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        int take=sub[i]+find(i+k,cnt-1,sub,k,n,dp);
        int nottake=find(i+1,cnt,sub,k,n,dp);
        return dp[i][cnt]= max(take,nottake);
    }

    void f(int ind, int cnt, vector<int>& sub, int k, vector<int>&ans, int n , vector<vector<int>>&dp){
        if(cnt==0){
            return;
        }
        
        if(ind>=n){
            return;
        }

        int take=sub[ind]+find(ind+k,cnt-1,sub,k,n,dp);
        int notake=find(ind+1,cnt,sub,k,n,dp);
        if(take>=notake){
            ans.push_back(ind);
            f(ind+k,cnt-1,sub,k,ans,n,dp);
        }else{
            f(ind+1,cnt,sub,k,ans,n,dp);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
     
      int num=nums.size();
        vector<int>sub;
        int sum=0;
        int i=0;
        int j=0;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1==k){
                sub.push_back(sum);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        int n=sub.size();
        vector<int>ans;
        vector<vector<int>>dp(n,vector<int>(4,-1));
        f(0,3,sub,k,ans, n,dp);
        return ans;


    }


};