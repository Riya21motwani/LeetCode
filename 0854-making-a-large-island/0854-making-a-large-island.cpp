class disjointset {
   
public:
     vector<int> rank, parent, size;
    disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        disjointset ds(n*n);
       
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(ncol>=0 &&nrow>=0&&ncol<n&&nrow<n && grid[nrow][ncol]==1){
                        int node=row*n+col;
                        int newnode=nrow*n+ncol;
                        ds.unionBySize(node,newnode);
                    }
                }
                
            }
        }
        
        int maxi=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                unordered_set<int>uset;
               if(grid[row][col]==1)continue;
                int drow[]={-1,0,1,0};
                int dcol[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(ncol>=0 &&nrow>=0&&ncol<n&&nrow<n && grid[nrow][ncol]==1){
                        uset.insert(ds.findUPar(nrow*n+ncol));
                    }
                }
                
                int totalsize=0;
                for(auto it:uset){
                    totalsize+=ds.size[it];
                    
                }
                totalsize+=1;
                maxi=max(maxi,totalsize);
                
            }
        }
        for(int i=0;i<n*n;i++){
            maxi=max(maxi,ds.size[ds.findUPar(i)]);
        }
        
        
        return maxi;
        
    }
};