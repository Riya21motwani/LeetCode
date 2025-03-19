class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
    
        int len=0;
     
        int maxi=0;
 
        int temp=nums[0];

        for(int i=0;i<n;i++){
            int bit=0;
            for(int j=i;j<n;j++){
                if((bit & nums[j]) !=0){
                    break;
                }
                
                maxi=max(maxi,j-i+1);
                bit|=nums[j];
            }
        }

       

       return maxi;
    }
};