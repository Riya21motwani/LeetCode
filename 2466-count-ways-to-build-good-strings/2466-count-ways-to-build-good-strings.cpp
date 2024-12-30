class Solution {
public:

    int m=1e9+7;

    int t(int current_length, int low, int high, int zero, int one, vector<int>& dp) {
      
        if (current_length > high) {
            return 0;
        }

        
        if (dp[current_length] != -1) {
            return dp[current_length];
        }

       
        int count = 0;
        if (current_length >= low && current_length <= high) {
            count = 1;
        }

       
        count =(count + t(current_length + zero, low, high, zero, one, dp))%m;
        count =(count+t(current_length + one, low, high, zero, one, dp))%m;

       
        return dp[current_length] = count%m;
        
    }

    int countGoodStrings(int low, int high, int zero, int one) {
       
        vector<int> dp(high + 1, -1);

       
        return t(0, low, high, zero, one, dp);
    }
};
