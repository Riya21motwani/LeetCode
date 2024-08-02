class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cntone=0;
        int maxcnt=0;
        int totalone=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
               totalone++;
            }
        }
        
        vector<int>v(2*n);
        for(int i=0;i<2*n;i++){
            v[i]=nums[i%n];
        }
        
        
        while(j<2*n){

        if(v[j]==1){
            cntone++;
        }
            if(j-i+1 >totalone){
                cntone-=v[i];
                i++;
            }
            
            maxcnt=max(maxcnt,cntone);
            j++;
        
        }
        
        return totalone-maxcnt;
    }
};