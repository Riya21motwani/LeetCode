class Solution {
public:
    
    
    
   int ispossible(vector<int> &nums, int t) {
   int n=nums.size();
       int sum=0;
       for(int i=0;i<n;i++){
         if(nums[i]%t==0){

        sum+=nums[i]/t;
         }
           else{
            sum+=nums[i]/t +1;
           }
       }
       return sum;
}
    int maximum(vector<int>& nums){
       int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
          maxi=max(maxi,nums[i]);
        }
    return maxi;
    }

int smallestDivisor(vector<int>& nums, int threshold) {
      int n=nums.size();
    int ans=maximum(nums);
    int l=1;
    int h=maximum(nums);
    while(l<=h){
       int mid=l+(h-l)/2;
        if(ispossible(nums,mid)<=threshold){
               ans=mid;
            h=mid-1;
        
        }
        else{
       l=mid+1;
        
        }
    }
    
    return ans;
    }
};