class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxlen=0;
        int cntzero=0;
        int i=0;
        int j=0;
        
        while(j<n){
            if(nums[j]==0){
                cntzero++;
            }
            while(cntzero>k){
                
                if(nums[i]==0){
                  cntzero--;
                }
                i++;
                
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        
        
        
        
        
        
        
        
        
        return maxlen;
    }
};