class Solution {
public:

    

    int maxScore(string s) {
        int  n=s.size();
       vector<int>l(n,0);
       vector<int>r(n,0);

       if(s[0]=='0'){
        l[0]=1;
       }

      for(int i=1;i<=n-2;i++){
        if(s[i]=='0'){
            l[i]=l[i-1]+1;
        }else{
            l[i]=l[i-1];
        }
      }

      if( s[n-1]=='1'){
        r[n-1]=1;
      }

      for(int i=n-2;i>0;i--){
        
        if(s[i]=='1'){
            r[i]=r[i+1]+1;
        }else{
            r[i]=r[i+1];
        }
      }

      int maxi=0;

      for(int i=0;i<n;i++){
        int ans=l[i]+r[i];
        maxi=max(maxi,ans);
      }

      return maxi;


    }
};