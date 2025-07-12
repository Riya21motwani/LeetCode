class Solution {
public:

  
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
    
        int maxi=INT_MIN;
        
        int prev=1;
        int suff=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
            prev*=nums[i];
             maxi=max(maxi,prev);
            }
            
            
            else{
                maxi=max(maxi,0);
                prev=1;
                
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i]!=0){
            suff*=nums[i];
            maxi=max(maxi,suff);
            }
            else{
                 maxi=max(maxi,0);
                suff=1;
            }
            
        }

    
        return maxi;
      
    }
};