class Solution {
public:
    int f(int i, int j, vector<int>& nums) {
        if(i > j) return 0;

         int pickLeft = nums[i] - f(i+1, j, nums);
        
        int pickRight = nums[j] - f(i, j-1, nums);

        return max(pickLeft, pickRight);
    }
    bool predictTheWinner(vector<int>& nums) {
        return f(0, nums.size() - 1, nums) >= 0;
    }
};
