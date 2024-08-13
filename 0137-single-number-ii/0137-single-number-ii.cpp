class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
       
        int res=0;
        
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int cntzero=0;
            int cntone=0;
            for(int &it:nums){
                if( (it & temp)==0){
                    cntzero++;
                }else{
                    cntone++;
                }
            }
            
            if(cntone%3==1){
                res=(res| temp);
            }
        }
        return res;
    }
};