class Solution {
public:
    
    
    bool isHappy(int n) {
        unordered_set<int>st;
      while(true){
          int sum=0;
          while(n!=0){
             int t=n%10;
              n=n/10;
              sum+=t*t;
              
              
              
}
          if(sum==1)return true;
          n=sum;
          if(st.find(n)!=st.end()){
                return false;
}
          st.insert(n);
      }
        return true;
    }
};