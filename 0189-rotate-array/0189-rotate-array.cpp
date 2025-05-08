class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
       k=k%n;
        if(n!=1){
        int t=n-k;

        reverse(nums.begin(),nums.begin()+t);
        reverse(nums.begin()+t,nums.begin()+n);
        reverse(nums.begin(),nums.end());
        }
    }
};