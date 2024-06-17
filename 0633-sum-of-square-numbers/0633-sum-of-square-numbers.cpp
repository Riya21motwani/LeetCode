# define ll long long int
class Solution {
public:
    bool judgeSquareSum(int c) {
    
       ll a=0;
    ll b=sqrt(c);
        while(a<=b){
            ll val=a*a+b*b;
            if(val>c){
                b--;
            }else if(val<c){
                a++;
            }else{
                 return true;
            }
        }
        return false;
    }
};