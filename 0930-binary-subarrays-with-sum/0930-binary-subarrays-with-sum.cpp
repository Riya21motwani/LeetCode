class Solution {
public:
    
    int f(vector<int>& nums, int k , int n){
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        if(k<0)return 0;
        while(j<n){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    
    
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return f(nums, goal, n)-f(nums, goal-1,n);
    }
};