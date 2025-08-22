class Solution {
public:

    bool possible(int &val,vector<int>& nums, int &k ){
        int sum=0;
        int cnt=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=val){
                sum+=nums[i];
            }else{
                cnt+=1;
                sum=nums[i];
            }
        }
        return cnt<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            total+=nums[i];
        }
        int l=maxi;
        int h=total;
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(possible(mid,nums,k)){
                h=mid-1;
                ans=mid;
                
            }else{
               
                l=mid+1;
            }
        }

        return ans;

    }
};