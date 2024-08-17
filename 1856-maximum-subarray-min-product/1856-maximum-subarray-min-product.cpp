class Solution {
public:
     #define mod 1000000007
    #define ll long long
//      vector<ll>findnsl(vector<int>&nums){
//         stack<int>st;
        
//         int m=nums.size();
//         vector<ll>nsl(m);
//         for(int i=0;i<m;i++){
            
//             if(st.empty()){
//                 nsl[i]=-1;
//             }
                
//         else{
//             while(!st.empty() && nums[st.top()]>=nums[i] ){
//                 st.pop();
//             }
//             if(!st.empty()){
//                 nsl[i]=st.top();
//             }
//             else{
//                 nsl[i]=-1;
//             }
           
//         }
//          st.push(i);
//         }
//         return nsl;
//     }
    
    
//     vector<ll>findnsr(vector<int>&nums){
//         stack<int>st;
        
//         int m=nums.size();
//         vector<ll>nsr(m);
//         for(int i=m-1;i>=0;i--){
            
//             if(st.empty()){
//                 nsr[i]=m;
//             }
                
//         else{
//             while( !st.empty() && nums[st.top()]>=nums[i] ){
//                 st.pop();
//             }
//             if(!st.empty()){
//                 nsr[i]=st.top();
//             }
//             else{
//                 nsr[i]=m;
//             }
           
//         }
//          st.push(i);
//         }
//         return nsr;
//     }
    int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>nse(n);
        vector<int>nle(n);
        vector<ll>presum(n);
        presum[0]=nums[0];
        
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+nums[i];
        }
        stack<int>st1;
        
       
        vector<ll>nsl(n,0);
        for(int i=0;i<n;i++){
            
            if(st1.empty()){
                nsl[i]=-1;
            }
                
        else{
            while(!st1.empty() && nums[st1.top()]>=nums[i] ){
                st1.pop();
            }
            if(!st1.empty()){
                nsl[i]=st1.top();
            }
            else{
                nsl[i]=-1;
            }
           
        }
         st1.push(i);
        }
        
        stack<int>st;
        
       
        vector<ll>nsr(n,0);
        for(int i=n-1;i>=0;i--){
            
            if(st.empty()){
                nsr[i]=n;
            }
                
        else{
            while( !st.empty() && nums[st.top()]>=nums[i] ){
                st.pop();
            }
            if(!st.empty()){
                nsr[i]=st.top();
            }
            else{
                nsr[i]=n;
            }
           
        }
         st.push(i);
        }
        ll ans=INT_MIN;
        for(int i=0;i<n;i++){
            int first=nsl[i]+1;
            int last=nsr[i]-1;
            
            ll sum= first==0? presum[last]:presum[last]-presum[first-1];
            ans=max(ans,sum*nums[i]);
        }
        
        
        return ans%mod;
    }
};
