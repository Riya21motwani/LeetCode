class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        if(start==goal)return 0;
        
        int val=start^goal;
        
        int cnt=0;
        while(val!=1){
            cnt+=val&1;
            val=val>>1;
        }
        if(val==1)cnt+=1;
        return cnt;
    }
};