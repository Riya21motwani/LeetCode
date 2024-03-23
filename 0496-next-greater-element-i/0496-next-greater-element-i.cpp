class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        stack<int>st;
        vector<int>ans(n2,-1);
        vector<int>ans1(n1,-1);
      for(int i=n2-1;i>=0;i--){
            int el=nums2[i];
          if(st.empty() ){
                st.push(el);
              ans[i]=-1;
              continue;
          }
          if(!st.empty() && st.top()>el){
            ans[i]=st.top();
              st.push(el);
              continue;
          }
          while(!st.empty() && st.top()<=el){
                st.pop();
          }
          if(st.empty() ){
            ans[i]=-1;
              st.push(el);
          }
          else{
              ans[i]=st.top();
              st.push(el);
              
          }
      }
        for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    
                    if(nums1[i]==nums2[j]){
                     ans1[i]=ans[j];
                    }

                }
        }
        return ans1;
    }
};