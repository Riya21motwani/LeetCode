class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
       int n = nums.size();

        int res=0;
        int flipcnt=0;
        vector<bool>isflipped(n,0);
        for(int i=0;i<n;i++){
            if(i>=k && isflipped[i-k]==1){
                flipcnt--;
            }
            
            if(flipcnt%2==nums[i]){
                if(i+k>n)return -1;
                res++;
                flipcnt++;
                isflipped[i]=1;
            }
        }
        return res;
        
    }
};