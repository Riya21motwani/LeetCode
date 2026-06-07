class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        vector<int>left(n,0);
        int r=0;
        vector<int>right(n,0);
        for(int i=1;i<n;i++){
            l+=nums[i-1];
            left[i]=l;
        }

        for(int i=n-2;i>=0;i--){
            r+=nums[i+1];
            right[i]+=r;
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=abs(left[i]-right[i]);
        }


        return ans;
    }
};