class Solution {
public:
    
    int solve(int n){
        int sum=0;
        while(n!=0){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    
    int addDigits(int num) {
        if(num>=0 && num<=9){
            return num;
        }
        
         while(num>=10){
             num=solve(num);
         }
        
        return num;
    }
};