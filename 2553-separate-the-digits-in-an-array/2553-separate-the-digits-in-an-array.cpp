class Solution {
public:

    void f(int i, vector<int>&ans, vector<int>&nums, int & tot){
        
        int cnt=0;
        int j=i;
        while(nums[j]!=0){
            int val=nums[j]%10;
            nums[j]=nums[j]/10;
            
            cnt++;
            ans.push_back(val);
            

        }
        reverse(ans.begin()+tot, ans.begin()+tot+cnt);
        tot+=cnt;
        
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        int tot=0;
        for(int i=0;i<nums.size();i++){
            f(i,ans,nums,tot);

        }

        return ans;
    }
};