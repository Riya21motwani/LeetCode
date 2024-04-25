class Solution {
public:
    
    
    bool ifpossible(vector<int>& bloomDay,int day, int m, int k){
        int n=bloomDay.size();
        int cnt=0;
        int  noofb=0;
        for(int i=0;i<n;i++){
             if(bloomDay[i]<=day){
                cnt++;

             }
            else{
                     noofb+=(cnt/k);
                     cnt=0;
            }
        }
        noofb+=(cnt/k);
        if(noofb>=m){
                return true;
        }
        return false;
    }
    int minimum(vector<int>&bloomDay){
        int mini=INT_MAX;
   int n=bloomDay.size();
        
        for(int i=0;i<n;i++){

             mini=min(mini,bloomDay[i]);
        }
        return mini;
    }
    
     int maximum(vector<int>&bloomDay){
         int maxi=INT_MAX;
   int n=bloomDay.size();
        for(int i=0;i<n;i++){

             maxi=max(maxi,bloomDay[i]);
        }
        return maxi;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
         long long val = m * 1ll * k * 1ll;
        if(val>n)return -1;
        int ans=-1;
        int l=minimum(bloomDay);
            int h=maximum(bloomDay);
       while(l<=h){
           int mid=l+(h-l)/2;
        if(ifpossible(bloomDay,mid,m,k)){

            ans=mid;
            h=mid-1;
           }
         else{
                   l=mid+1;
          }
        }
        return ans;
    }
};