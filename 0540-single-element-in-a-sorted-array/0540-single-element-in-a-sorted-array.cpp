class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        if(n==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[n-1]!=nums[n-2])return nums[n-1];
        l++;
        h--;
        while(l<=h){
          int mid=l+(h-l)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];
            if(nums[mid]==nums[mid-1]){
              if((mid-1)%2==1){
                h=mid-1;
              }
                else{
                  l=mid+1;
                }
            }
            else if(nums[mid]==nums[mid+1]){
               if(mid%2==0){
                   l=mid+1;
                }
                else{
                         h=mid-1;
                }
            }
           
        }
        return -1;
    }
};