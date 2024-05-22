class Solution {
public:
    
    
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> v;
        vector<int>bad;
        int n=nums.size();
        bad.push_back(0);
        for(int i=1;i<n;i++){
          if(nums[i]%2==nums[i-1]%2){
             bad.push_back(1);
          }else{
              bad.push_back(0);
          }
            
        }
        vector<int>presum(n);
        presum[0]=0;
        for(int i=1;i<n;i++){
              presum[i]=presum[i-1]+bad[i];
        }
        
        for(int i=0;i<queries.size();i++){
            int l=queries[i][0];
            int r=queries[i][1];
            
            if(presum[r]-presum[l]>=1)v.push_back(false);
            else{
            v.push_back(true);
            }
        }
        return v;
    }
};