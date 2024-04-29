class Solution {
public:
    
    
    
    int maximum(vector<vector<int>>& mat  , int  t, int n,int m){
        int maxi=INT_MIN;
        int ind=-1;
        for(int i=0;i<n;i++){
           if(mat[i][t] >maxi){

            maxi=mat[i][t];
               ind=i;
           }
        }
           
      return ind;
    }
    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int l=0;
        int h=m-1;
        while(l<=h){
          
            int mid=(l+h)/2;
            int row=maximum(mat,mid,n,m);
            
            int left=mid-1>=0 ? mat[row][mid-1]:-1;
            int right=mid+1<m ?mat[row][mid+1] :-1;
            
           
            
            if(left<mat[row][mid] &&  mat[row][mid]> right){
                     return {row,mid};
            }
            else if( left>mat[row][mid]){
                 h=mid-1;
            }
            else{

                  l=mid+1;
            }
        
        }
        return {-1,-1};
    }
};