class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> res;
        int n=grid.size();
        int m=grid[0].size();
        
        bool  flg1=true;
        bool flg2=true;
        int i=0;
        int j=0;
        
        for(int i=0;i<n;i++){

                if(flg1==true){
                    for(int j=0;j<m;j++){
                        if(flg2==true){
                            res.push_back(grid[i][j]);
                            flg2=false;
                        }else{
                             flg2=true;
                        }
                    }
                    flg1=false;
                }
                else{
                    for(int j=m-1;j>=0;j--){
                        if(flg2==true){
                            res.push_back(grid[i][j]);
                            flg2=false;
                        }else{
                             flg2=true;
                        }
                    }
                    flg1=true;
                }
        }



        return res;
    }
};