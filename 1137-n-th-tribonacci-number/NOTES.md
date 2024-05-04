//.with memoization
int dp[38];
int find( int n){
if(n==0)return 0;
if(n==1)return 1;
if(n==2)return 1;
if(dp[n]!=-1){
return dp[n];
}
return dp[n]= find(n-1)+find(n-2)+find(n-3);
}
int tribonacci(int n) {
memset(dp,-1,sizeof(dp));
return find(n);
}