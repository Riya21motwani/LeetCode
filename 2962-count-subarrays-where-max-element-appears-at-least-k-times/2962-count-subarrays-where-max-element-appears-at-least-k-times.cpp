class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int i=0;
        int j=0;
        long long  ans=0;
        int cnt=0;
        while(j<n){
           if(nums[j]==maxi){
            cnt++;
            while(cnt>=k){
                ans+=(n-j);
                if(maxi==nums[i]){
                    cnt--;
                }
                i++;
            }
           }
           j++;
        }

        return ans;
    }
};