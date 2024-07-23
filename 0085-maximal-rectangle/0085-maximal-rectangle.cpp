class Solution {
public:
    
    
    vector<int>findnsl(vector<int>&height){
        stack<int>st;
        
        int m=height.size();
        vector<int>nsl(m);
        for(int i=0;i<m;i++){
            
            if(st.empty()){
                nsl[i]=-1;
            }
                
        else{
            while(!st.empty() && height[st.top()]>=height[i] ){
                st.pop();
            }
            if(!st.empty()){
                nsl[i]=st.top();
            }
            else{
                nsl[i]=-1;
            }
           
        }
         st.push(i);
        }
        return nsl;
    }
    
    
    vector<int>findnsr(vector<int>&height){
        stack<int>st;
        
        int m=height.size();
        vector<int>nsr(m);
        for(int i=m-1;i>=0;i--){
            
            if(st.empty()){
                nsr[i]=m;
            }
                
        else{
            while( !st.empty() && height[st.top()]>=height[i] ){
                st.pop();
            }
            if(!st.empty()){
                nsr[i]=st.top();
            }
            else{
                nsr[i]=m;
            }
           
        }
         st.push(i);
        }
        return nsr;
    }
    
    
    
    
    int findmaxarea(  vector<int>&height){
        vector<int>nsr=findnsr(height);
        vector<int>nsl=findnsl(height);
        int m=height.size();
        vector<int>width(m);
        int maxi=0;
        for(int i=0;i<m;i++){
            width[i]=nsr[i]-nsl[i]-1;
        }
        
        for(int i=0;i<m;i++){
            int a=height[i]*width[i];
           if(maxi<a){
               maxi=a;
           }
        }
        return maxi;
        
    }
    
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m);
        for(int i=0;i<m;i++){
           if(matrix[0][i]=='1'){
               height[i]=1;
           }else{
               height[i]=0;
           }
        }
        int maxarea=findmaxarea(height);
        
        for(int row=1;row<n;row++){
            for(int col=0;col<m;col++){
                if(matrix[row][col]=='0'){
                    height[col]=0;
                }else{
                    height[col]+=1;
                }
            }
                
            maxarea=max(maxarea,findmaxarea(height));
        }
        return maxarea;
    }
    
    

 };