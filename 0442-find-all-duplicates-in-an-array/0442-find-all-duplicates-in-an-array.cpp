class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
          if(umap[nums[i]]>1){
             ans.push_back(nums[i]);
          }
        }
        return ans;
    }
};