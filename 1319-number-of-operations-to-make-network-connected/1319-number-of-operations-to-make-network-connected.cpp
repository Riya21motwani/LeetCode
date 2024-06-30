class Solution {
public:
    
    class disjointset {
        public:
    vector<int> rank, parent;
        int components;
public:
    disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        components=n;
    }

    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
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
        // components--;
    }
        int findcomponents(){
            return components;
        }
        
};
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int cntedges=0;
        int cntextra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findPar(u)==ds.findPar(v)){
                cntextra++;
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        int cntcomponent=0;
       for(int i=0;i<n;i++){
           if(i==ds.parent[i]){
               cntcomponent++;
           }
       }
        if(cntextra>=cntcomponent-1){
            return cntcomponent-1;
        }
        return -1;
    }
};