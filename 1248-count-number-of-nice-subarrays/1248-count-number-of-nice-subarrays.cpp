class Solution {
public:
     int f(vector<int>& nums, int k , int n){
        int i=0;
        int j=0;
        int sum=0;
        int cnt=0;
        if(k<0)return 0;
        while(j<n){
            sum+=nums[j]%2;
            while(sum>k){
                sum-=nums[i]%2;
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        return f(nums, k,n )-f(nums,k-1,n);

    }
};
