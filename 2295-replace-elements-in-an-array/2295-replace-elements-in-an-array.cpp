class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n=nums.size();
        int m=operations.size();
        unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
           umap[nums[i]]=i;
         }
        for(int j=0;j<m;j++){
             int key1=operations[j][0];
            int key2=operations[j][1];
            if(umap.find(key1)!=umap.end()){
                nums[umap[key1]]=key2;
                umap[key2]=umap[key1];
              
            }
            
            
        }
        return nums;
    }
};