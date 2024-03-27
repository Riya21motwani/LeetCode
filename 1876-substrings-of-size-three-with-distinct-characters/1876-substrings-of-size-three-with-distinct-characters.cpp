class Solution {
public:
    
    bool isvalid(string s){
        if(s.size()<2)return false;
        unordered_set<int>st;
        for(int i=0;i<s.size();i++){
      st.insert(s[i]);
        }
        if(st.size()==3){
        return true;
        }
        return false;
    }
    
    int countGoodSubstrings(string s) {
       int n=s.size();
        int cnt=0;
        if(n==1 || n==2 )return 0;
        
        for(int i=0;i<=n-3;i++){
            if(isvalid(s.substr(i,3))==true){
                  cnt++;
            }
        }
        return cnt;
    }
}; 