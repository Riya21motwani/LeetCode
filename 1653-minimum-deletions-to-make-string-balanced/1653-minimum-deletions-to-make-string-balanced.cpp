class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>pre(n,0);
        vector<int>post(n,0);
        
        for(int i=1;i<n;i++){
            if(s[i-1]=='b'){
                pre[i]=pre[i-1]+1;
            }else{
                pre[i]=pre[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(s[i+1]=='a'){
                post[i]=post[i+1]+1;
            }else{
                post[i]=post[i+1];
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            int maxi=(post[i]+pre[i]);
            mini=min(mini,maxi);
        }
        return mini;
    }
};