class Solution {
public:

    vector<int>parent;
    void Unionfind(int x , int y){
        parent[y]=x;
    }

    int findParent(int x){
        if(parent[x]==x){
            return x;
        }

        return parent[x]=findParent(parent[x]);
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int>cost(n);

        for(int i=0;i<n;i++){
            parent[i]=i;
            cost[i]=-1;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            int parent_u=findParent(u);
            int parent_v=findParent(v);

            if(parent_u!=parent_v){
                Unionfind(parent_u,parent_v);
                cost[parent_u] &=cost[parent_v];

            }
            cost[parent_u] &=w;
            
        }

    int m=query.size();
    vector<int>ans(m,-1);

        for(int i=0;i<query.size();i++){
            int u=query[i][0];
             int v=query[i][1];
             int parent_u=findParent(u);
              int parent_v=findParent(v);

              if(u==v){
                ans[i]=0;
              }
              
              else if(parent_u==parent_v){
                ans[i]=cost[parent_u];
              }else{
                ans[i]=-1;
              }
        }

    return ans;

    }
};