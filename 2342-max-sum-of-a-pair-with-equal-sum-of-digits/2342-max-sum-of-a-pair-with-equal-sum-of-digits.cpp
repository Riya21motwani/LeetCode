class Solution {
public:

    bool check(int val1, int val2){
        int sum1=0;
        int sum2=0;
        while(val1!=0){
            sum1+=val1%10;
            val1=val1/10;
        }
        while(val2!=0){
            sum2+=val2%10;
             val2=val2/10;
        }

        return sum1==sum2;
    }


    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(nums[i],nums[j])==true){
                    maxi=max(maxi,nums[i]+nums[j]);
                }
            }
        }

        return maxi;
    }
};