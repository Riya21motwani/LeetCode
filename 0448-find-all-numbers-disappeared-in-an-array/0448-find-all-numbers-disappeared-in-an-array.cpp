class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
         vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
                 int num=abs(nums[i]);
                 int ind=num-1;
             if(nums[ind]>0){
                 
                 nums[ind]=-nums[ind];
             }
         }
        for(int i=0;i<n;i++){
            
            if(nums[i]>0){
           ans.push_back(i+1);
            }
        }
        return ans;
    }
};