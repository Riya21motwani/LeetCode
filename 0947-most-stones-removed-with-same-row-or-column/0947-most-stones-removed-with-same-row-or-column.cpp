class disjointset {
    vector<int> rank, parent, size;
public:
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int mrow=0;
        int mcol=0;
        for(auto it:stones){
           mrow=max(mrow,it[0]);
           mcol=max(mcol,it[1]);
        }
        disjointset ds(mrow+mcol+1);
        unordered_map<int,int>umap;
        for(auto it:stones){
            int rowno=it[0];
            int colno=it[1]+1+mrow;
            ds.unionBySize(rowno,colno);
            umap[rowno]=1;
            umap[colno]=1;
        }
        int cntcomponent=0;
        for(auto it:umap){
            if(ds.findUPar(it.first)==it.first){
                    cntcomponent++;
            }
        }
        return n-cntcomponent;
    }
};