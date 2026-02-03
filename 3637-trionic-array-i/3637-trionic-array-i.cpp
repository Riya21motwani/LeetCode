class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

       
        while (i + 1 < n && nums[i + 1] > nums[i]) i++;
        if (i == 0) return false;  

        
        int mid1 = i;
        while (i + 1 < n && nums[i + 1] < nums[i]) i++;
        if (i == mid1) return false; 

        
        int mid2 = i;
        while (i + 1 < n && nums[i + 1] > nums[i]) i++;
        if (i == mid2) return false;

       
        return i == n - 1;
    }
};
