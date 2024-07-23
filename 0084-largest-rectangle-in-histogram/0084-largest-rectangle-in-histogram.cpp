class Solution {
public:
    vector<int>findnsr(vector<int>& heights){
         int n=heights.size();
        vector<int>nsr(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                nsr[i]=n;
            }else{
                while(!st.empty() &&heights[st.top()]>=heights[i]){
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
    vector<int>findnsl(vector<int>& heights){
         int n=heights.size();
        vector<int>nsl(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                nsl[i]=-1;
            }else{
                while(!st.empty() &&heights[st.top()]>=heights[i]){
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
    
     int findarea(vector<int>& heights){
         int n=heights.size();
         vector<int>nsr=findnsr(heights);
          vector<int>nsl=findnsl(heights);
          vector<int>width(n);
         for(int i=0;i<n;i++){
             width[i]=nsr[i]-nsl[i]-1;
             
         }
         int maxi=0;
         for(int i=0;i<n;i++){
            int a=heights[i]*width[i];
             if(maxi<a){
                 maxi=a;
             }
         }
         return maxi;
         
     }
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        return findarea(heights);
    }
};