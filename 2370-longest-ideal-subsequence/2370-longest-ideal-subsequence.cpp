class Solution {
public:
    int longestIdealString(string s, int k) {
          int n = s.length();
        
        vector<int> ans(26, 0);
        
        int result = 0;
        
        for(int i = 0; i < n; i++) {
            
            int curr    = s[i]-'a';
            int left    = max(0, curr-k);
            int right   = min(25, curr+k);

            int longest = 0;
            for(int j = left; j <= right; j++) {
                longest = max(longest, ans[j]);
            }
            
            ans[curr] = max(ans[curr], longest+1);
            result = max(result, ans[curr]);
        }
        
        return result;
    }
};