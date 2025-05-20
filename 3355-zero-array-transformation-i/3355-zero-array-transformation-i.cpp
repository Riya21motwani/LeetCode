class Solution {
public:

   
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n,0);
        for(int i=0;i<queries.size();i++){
            int s=queries[i][0];
            int e=queries[i][1];

            v[s]=v[s]+1;
            if(e+1<n){
                v[e+1]=v[e+1]-1;
            }
        }
      vector<int>presum(n,0);
      presum[0]=v[0];
        for(int i=1;i<n;i++){
           presum[i]=presum[i-1]+v[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i]>presum[i]){
                return false;
            }
        }

        return true;
    }
};