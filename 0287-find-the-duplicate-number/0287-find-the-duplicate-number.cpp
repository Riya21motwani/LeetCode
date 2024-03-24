class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        for(auto & it:umap){
            int key=it.first;
            int val=it.second;
            if(val>1){
                return it.first;
            }
        }
        return -1;
    }
};