class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>v=nums;
        vector<int>ans;
        sort(v.begin(),v.end());
        int n=nums.size();
        unordered_map<int,int>umap;
        for(int i=n-k;i<n;i++){
          umap[v[i]]++;
        }
        for(int i=0;i<n;i++){
            if(umap.find(nums[i])!=umap.end()){
                ans.push_back(nums[i]);
                umap[nums[i]]--;
                if(umap[nums[i]]==0){
                    umap.erase(nums[i]);
                }
            }
        }

        return ans;
        
    }
};