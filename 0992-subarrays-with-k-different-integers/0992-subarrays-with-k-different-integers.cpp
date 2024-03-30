class Solution {
    
public:
    
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        unordered_map<int,int>umap;
        while(j<n){
            umap[nums[j]]++;
            
            while(umap.size()>k){
               umap[nums[i]]--;
                if(umap[nums[i]]==0){
                      umap.erase(nums[i]);
                }
                i++;
            }
            cnt+=j-i+1;
           j++;
        }
        
        return cnt;
        
    }
    
    
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return solve(nums,k)-solve(nums,k-1);
    }
};