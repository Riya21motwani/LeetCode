class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int maxi=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]-prev>0){
                prev=nums[i];
                sum+=nums[i];
            }else{
                sum=nums[i];
                prev=nums[i];
            }
            maxi=max(maxi,sum);
        }
        return sum;
    }
};