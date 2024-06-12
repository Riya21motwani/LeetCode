class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
       map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        int i=0;
        for(auto &it:umap){
            int freq=it.second;
            while(freq>0 && i<n){
                nums[i++]=it.first;
                freq--;
            }
        }
    }
};