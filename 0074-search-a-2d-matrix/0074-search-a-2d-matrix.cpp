class Solution {
public:
    
    
    bool find ( vector<int> matrix, int m, int target){
       
        int l=0;
        int h=m-1;
        while(l<=h){
           int mid=(l+h)/2;
            if(matrix[l]<=target && target<=matrix[h]){
                if(matrix[mid]<target){
                     l=mid+1;
                }
                else if(matrix[mid]>target){

                            h=mid-1;
                }
                
                else {

                 return true;
                }
            
            }
            
            else{
                       return false;
            }
        
        }
        
        return false;
    
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){

           if(find(matrix[i],m, target)==true){
                 return true;
           }
        }
        return false;
    }
};