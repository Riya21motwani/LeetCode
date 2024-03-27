class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        
        int cnt=0;
        int i=0;
        int j=0;
        int p=1;
        if(k<=1)return 0;
        while(j<n){
           p=p*nums[j];
              
            while(p>=k){
               p=p/nums[i];
                i++;
               
            }
            cnt+=j-i+1;
                  j++;

        }
        return cnt;
    }
};