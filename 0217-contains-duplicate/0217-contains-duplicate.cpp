class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=0;
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
            if(umap[nums[i]]>1){
                return true;
            }
        }
        

     return false;   
    }
};