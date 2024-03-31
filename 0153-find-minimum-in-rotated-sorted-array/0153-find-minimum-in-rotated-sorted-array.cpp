class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int mini=INT_MAX;
        while(l<=h){
          int mid=(l+(h-l)/2);
            if(nums[ l]<=nums[mid]){
                mini=min(mini,nums[l]);
                l=mid+1;
            }
            else if(nums[mid] <= nums[h]){
                mini=min(mini,nums[mid]);
                h=mid-1;
}
            
        }
        return mini;
    }
};