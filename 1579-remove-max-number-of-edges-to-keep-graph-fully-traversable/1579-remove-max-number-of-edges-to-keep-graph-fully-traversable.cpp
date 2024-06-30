class disjointset {
    private:
    vector<int> rank, parent;
    int components;
public:
    disjointset(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        components=n;
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
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
        components--;
    }
    
    
    bool checkcomponent(){
       return components==1;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
       
        auto lambda=[&](vector<int>&v1,vector<int>&v2){
            return v1[0]>v2[0];
        };
         disjointset alice(n);
        disjointset bob(n);
        
        sort(edges.begin(),edges.end() ,lambda);
        
        int cntedges=0;
        for(auto it :edges){
            int type=it[0];
            int u=it[1];
            int v=it[2];
            
            if(type==3){
                bool flag=false;
                if(alice.findPar(u)!=alice.findPar(v)){
                   alice.unionByRank(u,v);
                    flag=true;
                }
                if(bob.findPar(u)!=bob.findPar(v)){
                   bob.unionByRank(u,v);
                    flag=true;
                }
                if(flag==true){
                    cntedges++;
                }
            }
            else if(type==1){
                if(alice.findPar(u)!=alice.findPar(v)){
                   alice.unionByRank(u,v);
                    cntedges++;
                }
            }
            else{
                if(bob.findPar(u)!=bob.findPar(v)){
                bob.unionByRank(u,v);
                 cntedges++;
                }
            }
        
        }
        if(alice.checkcomponent()==true && bob.checkcomponent()==true){
            return edges.size()-cntedges;
        }
        return -1;
    }
};


