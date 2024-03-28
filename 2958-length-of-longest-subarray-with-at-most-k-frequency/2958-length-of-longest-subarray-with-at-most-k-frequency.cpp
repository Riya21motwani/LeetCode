class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<int,int>umap;
        while(j<n){
            umap[nums[j]]++;
             while(umap[nums[j]]>k){
                umap[nums[i]]--;
                 i++;
             }
           maxi=max(maxi,j-i+1) ;
            j++;
        }
        return maxi;
    }
};