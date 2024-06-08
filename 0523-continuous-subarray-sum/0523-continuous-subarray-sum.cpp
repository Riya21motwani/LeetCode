class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>umap;
        umap[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
              sum+=nums[i];
              int remain=sum%k;
             if(umap.find(remain)!=umap.end()){
                 if( i-umap[remain]>1){
                       return true;
                 }
             }else{
              umap[remain]=i;
             }
        }
        return false;
    }
};