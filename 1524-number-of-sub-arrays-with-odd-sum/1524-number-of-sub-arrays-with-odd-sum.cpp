class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>presum(n,0);
        int cnt=0;
        presum[0]=arr[0];
        int  cnteve=0;
        int cntodd=0;
        if(arr[0]%2==1){
            cntodd++;
            cnt++;

        }else{
            cnteve++;
        }

        for(int i=1;i<n;i++){

             presum[i]=presum[i-1]+arr[i];
            
            if(presum[i]%2==1 && cnteve>0){
                cnt=(cnt+cnteve)% (1000000007);
            }else if(presum[i]%2==0 && cntodd>0){
                cnt+=cntodd;
            }
            if(presum[i]%2==1){
                cntodd++;
                cnt++;

             }else{
                 cnteve++;
              }
           
            
        }
        
        return cnt % (1000000007);

        
    }
};