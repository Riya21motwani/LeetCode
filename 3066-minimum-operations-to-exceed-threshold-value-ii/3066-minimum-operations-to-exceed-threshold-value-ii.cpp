class Solution {
public:
    bool isValid(vector<int>& nums, int k) {
        for (int num : nums) {
            if (num < k) return false;
        }
        return true;
    }

    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        
        while (true) {
            sort(nums.begin(), nums.end());
            
            if (nums.size() < 2) break;
            
            long long newVal = static_cast<long long>(nums[0]) * 2 + nums[1];  
            nums.erase(nums.begin(), nums.begin() + 2);
            nums.push_back(static_cast<int>(newVal)); 
            cnt++;

            if (isValid(nums, k)) return cnt;
        }

        return cnt;
    }
};
