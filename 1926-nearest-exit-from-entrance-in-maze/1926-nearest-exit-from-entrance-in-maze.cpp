class Solution {
public:

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));

        int sr=entrance[0];
        int sc=entrance[1];
        int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        int cnt=0;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        maze[sr][sc]='+';
     

        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
               
               if ((row != sr || col != sc) && (row == n - 1 || row == 0 || col == 0 || col == m - 1)) {
    return cnt;
}

                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 &&ncol>=0 && nrow<n && ncol<m &&  maze[nrow][ncol]!='+'){
                        q.push({nrow,ncol});
                         maze[nrow][ncol]='+';
                    }
                }
            }
            cnt++;
        }

        return -1;
        
    }
};