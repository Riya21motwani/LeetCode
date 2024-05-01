class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
           total^=nums[i];
        }
        
        int difference=total^k;
        return __builtin_popcount(difference);
    }
};