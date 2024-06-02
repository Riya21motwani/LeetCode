class Solution {
public:
    
    bool subsetSumToK(int n, int k, vector<int> &arr) {
   vector<bool> prev(k+1,0),curr(k+1,0);
       curr[0]=prev[0]=true;
       if(arr[0]<=k) prev[arr[0]] = true;
      for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
           
            bool notTaken = prev[target];

          
            bool taken = false;
            if (arr[ind] <= target) {
                taken = prev[target - arr[ind]];
            }

            
            curr[target] = notTaken || taken;
        }
        prev=curr;
    }

    
    return prev[k];
}
    
    
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
              totalsum+=nums[i];
        }
        if(totalsum%2==1)return false;
        int partition=totalsum/2;
        return subsetSumToK(n,partition,nums);
    }
};