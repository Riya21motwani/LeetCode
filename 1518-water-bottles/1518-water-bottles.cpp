class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int c=0;
       while(numExchange<= numBottles){
           c+=numExchange;
           numBottles-=numExchange;
           numBottles+=1;
           
       }
        return c+numBottles;
    }
};