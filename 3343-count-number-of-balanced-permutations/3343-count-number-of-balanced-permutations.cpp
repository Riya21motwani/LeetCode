class Solution {
public:
    int n;
    int mod=1e9+7;
    long long total=0;
    long long  totalPermutation;

    int findPow(long long a , long long b){
        if(b==0){
            return 1;
        }
        long long half= findPow(a,b/2);
        long long res=(half*half)%mod;
        if(b%2==1){
            res=(res*a)%mod;
        }
        return res;
    }


    int f(int digit, int even_index_cnt, int even_sum , vector<int>&freq,vector<long long>&fermat ){
        if(digit==10){
            if(even_sum == total / 2 && even_index_cnt == (n + 1) / 2)
{
                return totalPermutation;
            }

            return 0;
        }

        long long ways=0;
        for(int cnt=0;cnt<=min(freq[digit],(n+1)/2 -even_index_cnt);cnt++){
            int digits_in_even_pos=cnt;
            int  digits_in_odd_pos=freq[digit]-cnt;
            long long divide=(fermat[digits_in_even_pos]*fermat[digits_in_odd_pos])%mod;
            long long val=f(digit+1,even_index_cnt+digits_in_even_pos,even_sum+ digits_in_even_pos*digit,freq,fermat);
            ways=(ways+(val*divide)%mod)%mod;
        }


        return ways;

    }




    int countBalancedPermutations(string num) {
        n=num.size();
        
        vector<int>freq(10,0) ;
        for(int i=0;i<n;i++){
            freq[num[i]-'0']++;
            total+=(num[i]-'0');
        }
        if(total%2==1){
            return 0;
        }

        vector<long long >fact(n+1,1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%mod;
        }

totalPermutation = (1LL * fact[(n + 1) / 2] * fact[n / 2]) % mod;

        vector<long long>fermat(n+1,0);

        for(int i=0;i<=n;i++){
            fermat[i]=findPow(fact[i],mod-2) %mod;
        }

        int digit=0;
        int even_index_cnt=0;
        int even_sum=0;
        return f( digit,  even_index_cnt,  even_sum , freq,fermat);

    }
};