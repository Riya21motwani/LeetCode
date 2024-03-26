class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size();
        bool containing1=false;
        for(int i=0;i<n;i++){
         if(nums[i]==1){
           containing1=true;
         }
            if(nums[i]<=0 || nums[i]>n){
                 nums[i]=1;
            }
        }
        if(containing1==false)return 1;
        for(int i=0;i<n;i++){
                int num=abs(nums[i]);
            int ind=num-1;
            if(nums[ind] >0 ){
                   nums[ind]=-nums[ind];
            }
        }
        for(int i=0;i<n;i++){
          if(nums[i]>0){
           return i+1;
}
}
        return n+1;
    }
};