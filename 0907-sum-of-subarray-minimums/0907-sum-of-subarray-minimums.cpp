class Solution {
public:
    
     vector<int>findnsr(vector<int>& arr){
          int n=arr.size();
         vector<int>nsr(n);
         stack<int>st;
         for(int i=n-1;i>=0;i--){
             if(st.empty()){
                 nsr[i]=n;
             }else{
                 while(!st.empty() &&  arr[st.top()] >=arr[i]){
                     st.pop();
                 }
                 if(st.empty()){
                     nsr[i]=n;
                     
                 }else{
                     nsr[i]=st.top();
                 }
             }
             st.push(i);
         }
         return nsr;
     }
     vector<int>findnsl(vector<int>& arr){
          int n=arr.size();
         vector<int>nsl(n);
         stack<int>st;
         for(int i=0;i<n;i++){
             if(st.empty()){
                 nsl[i]=-1;
             }else{
                 while(!st.empty() &&  arr[st.top()] >arr[i]){
                     st.pop();
                 }
                 if(st.empty()){
                     nsl[i]=-1;
                     
                 }else{
                     nsl[i]=st.top();
                 }
             }
             st.push(i);
         }
         return nsl;
     }
    
    
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int tsum=0;
        int mod=1e9+7;
        vector<int>nsl=findnsl(arr);
        vector<int>nsr=findnsr(arr);
        for(int i=0;i<n;i++){
            long long l=(i-nsl[i])*(nsr[i]-i);
            l=l*arr[i];
            tsum=(tsum+l)%mod;
            
        }
        
        return tsum;
    }
};