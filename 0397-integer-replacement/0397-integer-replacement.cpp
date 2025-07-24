class Solution {
public:

    int f(long long n, int m){
        
        if(n==1){
            return 0;
        }
        int eve=INT_MAX;
        int odd=INT_MAX;
        if(n%2==0){
            eve=1+f(n/2 , m);
        }
        else{
            odd=1+min(f(n-1,m),f(n+1,m));
        }

        return min(odd,eve);
       
        
    }

    int integerReplacement(int n) {
        return f((long long)n,n);
    }
};