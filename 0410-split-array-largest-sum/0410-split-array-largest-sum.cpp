class Solution {
public:
    
    int solve(vector<int>& nums, int mid){
       int n=nums.size();
       int t=0;
        int cnt=0;
        int newk=1;
        for(int i=0;i<n;i++){
            if(t+nums[i]<=mid){
               t+=nums[i];
                
            }
            else{
                t=nums[i];
                newk+=1;
              
                
                
            }
            
        }
        
        return newk;
        
    }
    
    int maximum(vector<int>& nums){
          int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){

            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    
    int summision(vector<int>& nums){
     int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
}
        return sum;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=maximum(nums);
        int ans=0;
        int h=summision(nums);
        while(l<=h){
            int mid=l+(h-l)/2;
            if(solve(nums,mid)>k){
               l=mid+1;
            }
            else{
                ans=mid;
                 h=mid-1;
            }
            
        }
        return ans;
    }
};