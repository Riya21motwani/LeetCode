class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
       
        vector<vector<int>>dir={{0,1} , {1,0},{0,-1} ,{-1,0}};
        int cnt=0;
        int d=0;
        
        ans.push_back({rStart,cStart});
        
        while(ans.size()<(rows*cols)){
            
            if(d==0 || d==2){
                cnt++;
            }
            
            
            for(int i=0;i<cnt;i++){
            rStart+=dir[d][0];
            cStart+=dir[d][1];
            if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                ans.push_back({rStart , cStart});
            }
          }
            d=(d+1)%4;
        } 
        
        return ans;
    }
};