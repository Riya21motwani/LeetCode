class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int mid=0;
        int h=n-1;

        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }else if(nums[mid]==2){
                swap(nums[mid],nums[h]);
                h--;
            }
        }
    }
};