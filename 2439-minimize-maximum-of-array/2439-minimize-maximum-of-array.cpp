class Solution {
public:

    bool possible(int ind, vector<int>& nums){

        vector<long long>a(nums.begin(),nums.end());
        int n=nums.size();

        for(int i=0;i<n-1;i++){
                if(a[i]>ind){
                    return false;
                }
                int val=ind-a[i];
                a[i+1]=a[i+1]-val;
        }
        

    return a[n-1]<=ind;   
    }

    int maxi(vector<int>& nums){
        int n=nums.size();
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int l=1;
        int h=maxi(nums);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;

            if(possible(mid,nums)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        if(ans==-1){
            return maxi(nums);
        }

        return ans;
    }
};