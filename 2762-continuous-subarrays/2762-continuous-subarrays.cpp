class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long ans=0;
        unordered_map<int,int>umap;
        int maxi=nums[0];
        int mini=nums[0];
        while(j<n){
             mini=min(mini,nums[j]);
             maxi=max(maxi,nums[j]);
             if(maxi-mini>2){
                i++;
                mini=nums[i];
                maxi=nums[i];
                for(int k=i;k<=j;k++){
                    mini=min(mini,nums[k]);
                    maxi=max(maxi,nums[k]);
                }              
             }else{
                ans+=(j-i+1);
                j++;
             }        
        }

        return ans;
    }
};