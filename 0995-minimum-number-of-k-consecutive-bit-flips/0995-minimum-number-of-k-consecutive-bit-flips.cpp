class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        int flips = 0;
        vector<bool> is(n, false);
        int flipC = 0;

        for(int i = 0; i < n; i++) {
            if(i >= k && is[i-k] == true){
                flipC--;                     
            }
            
            if(flipC % 2 == nums[i]) {
                if(i+k > n){
                    return -1;
                }
                flipC++;
                is[i] = true;
                flips++;
            }
        }

        return flips;
    }
};