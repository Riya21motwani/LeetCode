class Solution {
public:

    bool possible( int &mid , vector<int>& nums, int k){
        
        int cnt=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=mid){
                cnt++;
                i++;
            }
        }

        return cnt>=k;
    }

    int maximum(vector<int>& nums){
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }

    int minCapability(vector<int>& nums, int k) {
        
        int n=nums.size();

        int l=1;
        int h=maximum(nums);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;

            if(possible(mid,nums,k)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};