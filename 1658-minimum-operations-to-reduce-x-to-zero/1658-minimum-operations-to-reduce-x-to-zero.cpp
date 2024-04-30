class Solution {
public:
   
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int>umap;
        int longestsubarray=INT_MIN;
        umap[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            umap[sum]=i;
        }
        int rem=sum-x;
        if(rem<0)return -1;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
             if(umap.find(sum-rem)!=umap.end()){
                int ind=umap[sum-rem];
                 longestsubarray=max(longestsubarray,i-ind);
             }
        }
        return longestsubarray==INT_MIN? -1: n-longestsubarray ;
    }
};