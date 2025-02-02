class Solution {
public:
    bool check(vector<int>& nums) {
      int n=nums.size();
      if(n==2){
        return true;
      }
      int cnt=0;
      vector<int>v=nums;
      sort(v.begin(),v.end());
      if(v==nums){
        return true;
      }

      if(nums[0]<nums[n-1]){
        return false;
      }
     
      for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1] ){
            cnt++;
        }
      }

      return cnt==1;

    }
};