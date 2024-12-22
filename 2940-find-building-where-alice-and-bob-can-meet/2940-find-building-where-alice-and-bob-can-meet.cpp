class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int m=queries.size();
        vector<int>ans;
        
        for(int i=0;i<m;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            bool flag=false;
            for(int j=max(u,v);j<n;j++){
                if(heights[u]<=heights[j] && heights[v]<=heights[j]){
                    ans.push_back(j);
                    flag=true;
                    break;
                }
                
            }
            if(flag==false){
                    ans.push_back(-1);
                }
        }

        return ans;
    }

};