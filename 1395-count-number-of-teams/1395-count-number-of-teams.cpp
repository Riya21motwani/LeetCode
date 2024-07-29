class Solution {
public:
    
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int total=0;
        for(int j=1;j<n-1;j++){
            int cntsmallerleft=0;
              int    cntlargerleft=0;
              int    cntsmallerright=0;
                 int cntlargerright=0;
            for(int i=0;i<j;i++){
                if(rating[i]<rating[j]){
                    cntsmallerleft++;
                }
                if(rating[i]>rating[j]){
                    cntlargerleft++;
                }
                
            }
            for(int k=j+1;k<n;k++){
                if(rating[k]<rating[j]){
                    cntsmallerright++;
                }
                if(rating[k]>rating[j]){
                    cntlargerright++;
                }
                
            }
            
            total+= cntsmallerleft*cntlargerright +cntlargerleft*cntsmallerright;
            
        }
        
        return total;
          
    }
};