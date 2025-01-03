class Solution {
public:

    



    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
       
        int cnt=0;
        long long tsum=0;
        vector<long long>presum;

        for(int l=0;l<n;l++){
            tsum+=nums[l];
            presum.push_back(tsum);
            
        }
        

        for(int i=0;i<=n-2;i++){
            if(tsum-presum[i]<=presum[i]){
                cnt++;
            }
        }

        return cnt;
      
    }
};