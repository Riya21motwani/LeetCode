class Solution {
public:

    int f( int ind , vector<int>& coins, int amount){
    
        if(ind==0){
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            else{
                  return 1e9;
            }
        }
          int notake=f(ind-1,coins,amount);

        int take=1e9;
        if(coins[ind]<=amount){
            take= 1+f(ind,coins,amount-coins[ind]);
        }

      

        return min(take,notake);


    }


    int coinChange(vector<int>& coins, int amount) {
        
            int n=coins.size();
        if(f(n-1,coins,amount)>=1e9){
            return -1;
        }

        return f(n-1,coins,amount);
    }
};