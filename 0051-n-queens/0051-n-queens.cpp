class Solution {
public:
    vector<vector<string>>res;
    
    bool isvalid(vector<string>&board,int row,int col,int n){

        for(int i=row-1;i>=0;i--){
                if(board[i][col]=='Q'){
             return false;
                }
        }
        for(int i=row-1,j=col-1; i>=0 && j>=0;i--, j--){
                 if(board[i][j]=='Q'){
             return false;
                 }
        }
        for(int i=row-1,j=col+1; i>=0 && j<n;i--, j++){
                 if(board[i][j]=='Q'){
             return false;
                 }
        }
        return true;
    
    }
    
    void solve(int row, vector<string>&board,int n){
         if(row==n){
          res.push_back(board);
             return;
         }
        
        for(int col=0;col<n;col++){
             if(isvalid(board,row,col,n)){
                board[row][col]='Q';
                 solve(row+1,board,n);
                 board[row][col]='.';
             }
        }
        
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        //s1
        vector<string>board(n,string(n,'.'));
        
        solve(0,board,n);
        return res;
        
        
    }
};