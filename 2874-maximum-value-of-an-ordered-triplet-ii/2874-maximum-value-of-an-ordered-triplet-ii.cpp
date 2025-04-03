class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        int maxi1=nums[0];
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            maxi1=max(maxi1,nums[i]);
            pre[i]=maxi1;
        }
        int maxi2=nums[n-1];
        suf[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            maxi2=max(maxi2,nums[i]);
            suf[i]=maxi2;
        }
        long long nmaxi=0;
        for(int i=0;i<n;i++){
            if(i-1>=0 && i+1<n){
            nmaxi=max(nmaxi, (long long)((pre[i-1]-nums[i])*(long long)suf[i+1]));
            }
        }
        return nmaxi;

    }
};