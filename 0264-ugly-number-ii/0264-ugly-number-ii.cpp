class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>nums(n+1);
        nums[1]=1;
        int t2=1;
        
        int t3=1;
        int t5=1;
        
        for(int i=2;i<=n;i++){
            int secu=nums[t2]*2;
            int thiru=nums[t3]*3;
            int fifu=nums[t5]*5;
            
            int mini=min({secu,thiru,fifu});
            nums[i]=mini;
            if(mini==secu){
                t2++;
            }
             if(mini==thiru){
                t3++;
            }
             if(mini==fifu){
                t5++;
            }
        }
        
        return nums[n];
    }
};