class Solution {
public:
    
     
    int ans=INT_MAX;
    
    void solve(int idx,vector<int>& cookies, int k,vector<int>&t){
         int n=cookies.size();       
        if(idx>=n){
           int maxi=*max_element(t.begin(),t.end());
            ans=min(maxi,ans);
            return;
        }
                  
        
                int cookie=cookies[idx];
                for(int i=0;i<k;i++ ){
                    t[i]+=cookie;
                    solve(idx+1,cookies,k,t);
                    t[i]-=cookie;
                }
        
           }
    
     
    int distributeCookies(vector<int>& cookies, int k) {
                
              vector<int>t(k);
              int n=cookies.size();
               solve(0,cookies,k,t);
             return ans;
        
                
               
    }
};