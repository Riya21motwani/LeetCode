class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
      long long  ans=0;
        for(int i=0;i<n;i++){
            int small=nums[i];
            int large=nums[i];
            for(int j=i+1;j<n;j++){
                large=max(large,nums[j]);
                small=min(small,nums[j]);
                ans+=large-small;
            }
        }
        return ans;
    }
};