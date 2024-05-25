class Solution {
public:
    int m;
    int maxcnt=INT_MIN;
    void solve(int idx,int  cnt, int n, vector<int>&result, vector<vector<int>>& requests){
         if(idx==m){
            bool allzero=true;
             for(auto &x : result){
                   if(x!=0){
                      allzero=false;
                       break;
                   }
             }
             if(allzero){
              maxcnt=max(maxcnt,cnt);
           }
             
             return;
         }

        int from=requests[idx][0];
        int to=requests[idx][1];
        
        result[from]--;
        result[to]++;
        
        solve(idx+1,cnt+1,n,result,requests);
        result[from]++;
        result[to]--;
        
        solve(idx+1,cnt,n,result,requests);
        
        
    }
    
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
         m=requests.size();
    
        vector<int>result(n,0);
        solve(0,0,n,result,requests);
        return maxcnt;
    }
};