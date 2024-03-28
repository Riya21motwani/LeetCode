class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int len=0;
        int mini=INT_MAX;
        unordered_map<int,int>umap;
        int i=0;
        int j=0;
       while(j<n){
          
            sum+=nums[j];
           while(sum>=target){
             mini=min(mini,j-i+1);
               sum-=nums[i];
               i++;
           }
            
            j++;
        }
       if(mini==INT_MAX){
             return 0;
       }
        return mini;
    }
};