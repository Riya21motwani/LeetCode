class Solution {
public:
    typedef pair<int,int>p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
       
         int drow[]={-1,0,1,0};
        int dcol[]={0,-1,0,1};
        // priority_queue<p,vector<p>,greater<p>>pq;
         priority_queue<pair<int, p>,
                       vector<pair<int, p>>,
                       greater<pair<int,p>>>
            pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 &&col==m-1)return diff;
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 &&ncol>=0 &&nrow<n &&ncol<m){
                      int maxdiff=max(diff,abs(heights[nrow][ncol]-heights[row][col]));
                    if(maxdiff<dis[nrow][ncol]){
                        dis[nrow][ncol]=maxdiff;
                        pq.push({maxdiff,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};