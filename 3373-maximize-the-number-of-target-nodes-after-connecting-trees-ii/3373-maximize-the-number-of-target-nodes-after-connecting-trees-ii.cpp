class Solution {
public:

   void f(int node, unordered_map<int,vector<int>>&adj , vector<int>&eve, int &parent , int &cntone , int &cntzero){
      
        if(eve[node]==1){
            cntone++;
        }
        else if(eve[node]==0){
            cntzero++;
        }
        for(auto it:adj[node]){
            if(it!=parent){
                if(eve[node]==0){
                    eve[it]=1;
                }
                else{
                    eve[it]=0;
                }
                f(it,adj,eve,node,cntone,cntzero);
            }
        }
    }

    unordered_map<int,vector<int>>getadj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        unordered_map<int,vector<int>>adj1=getadj(edges1);
        unordered_map<int,vector<int>>adj2=getadj(edges2);
        vector<int>eve1(n+1,-1);
        vector<int>eve2(m+1,-1);
        int cntone1=0;
        int cntzero1=0;
       eve1[0]=0;
       int parent=-1;
        f(0,adj1,eve1,parent,cntone1, cntzero1);
        int cntone2=0;
        int cntzero2=0;
         eve2[0]=0;
         int parent2=-1;
        f(0,adj2,eve2,parent2,cntone2, cntzero2);
        int maxi=max(cntone2,cntzero2);
        for(int i=0;i<=n;i++){
            if(eve1[i]==0){
                eve1[i]=cntzero1+maxi;
            }else{
                eve1[i]=cntone1+maxi;
            }
        }


       return eve1;
    }
};