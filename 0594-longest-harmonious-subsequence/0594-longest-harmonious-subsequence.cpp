class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        int maxi=nums[i];
        int mini=nums[j];
        int ans=0;
        while(j<n){

            maxi=max(maxi,nums[j]);
            if(maxi-mini==1){
                ans=max(ans,j-i+1);
            }
            while(maxi-mini>1){
                mini=nums[i+1];
                i++;
            }
            j++;
            
        }
        return ans;
    }
};
