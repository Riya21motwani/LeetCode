class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=-1;
        int l=0;
        int n=nums.size();
        int h=n-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]>target){
                ans=mid;
                h=mid-1;
            }else if(nums[mid]<target){
                l=mid+1;
            }else{
                return mid;
            }
        }
        if(ans==-1){
            return n;
        }

        return ans;
    }
};