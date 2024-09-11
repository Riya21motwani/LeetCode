class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        if(start==goal){
            return 0;
        }
        
        int n=start^goal;
        
        //no of setbits calculation
        
        int cnt=0;
        while(n!=1){
            cnt+=n&1;
            n=n>>1;
        }
        if(n==1)cnt+=1;
        return cnt;
    }
};