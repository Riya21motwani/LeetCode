class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            int num=abs(nums[i]);
            int ind=num-1;
            if(nums[ind]<0){

                ans.push_back(abs(nums[i]));
              }
            else{
                 nums[ind]=-nums[ind];
            }

        }
        return ans;
    }
};