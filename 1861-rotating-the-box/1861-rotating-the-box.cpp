class Solution {
public:

    void f(vector<char>&a){
        int n=a.size();
        int i=n-1;
        int j=n-1;
        while(j>=0){
            if(a[j]=='*'){
                i=j-1;
                j--;
            }
            else if(a[j]=='#'&& i!=j){
                a[i]='#';
                a[j]='.';
                i--;
                j--;
                
            }else if(a[j]=='#' && i==j){
                j--;
                i--;
            }
            else{
                j--;
            }
        }

    }


    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n=boxGrid.size();
        int m=boxGrid[0].size();
        vector<vector<char>>res(m,vector<char>(n));

        for(int i=0;i<n;i++){
            f(boxGrid[i]);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res[i][j]=boxGrid[j][i];
            }
        }
            for(int i=0;i<m;i++){
                reverse(res[i].begin(),res[i].end());
            }


            


            return res;
    }
};