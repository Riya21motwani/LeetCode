class Solution {
public:

    int f(int ind, vector<int>& nums , int total){
        int n=nums.size();
        if(ind==n){
            return total;
        }

        int take=f(ind+1,nums,total^nums[ind]);
        int notake=f(ind+1,nums,total);

        return take+notake;
    }

    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        return f(0,nums,total);
        

       
    }
};