class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>umap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        int k=0;
        for(int i=-100;i<=100;i++){
            if(umap[i] >0){
                nums[k]=i;
                k++;
            }
        }
        
        return k;
    }
};