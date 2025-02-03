class Solution {
public:

    bool decr(int i ,int j , vector<int>& nums){
         int n=nums.size();
         for(int k=i;k<j;k++){
            if(nums[k+1]-nums[k]>=0){
                return false;
            }
         }

         return true;
    }

    bool incr(int i ,int j , vector<int>& nums){
         int n=nums.size();
         for(int k=i;k<j;k++){
            if(nums[k+1]-nums[k]<=0){
                return false;
            }
         }

         return true;
    }

    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool inc=incr(i,j,nums);
                bool dec=decr(i,j,nums);
                if(inc || dec){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        if(maxi==0){
            return 1;
        }

        return maxi;
    }
};