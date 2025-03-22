class Solution {
public:

  

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         vector<int>vis(n,0);
         int cnt=0;
         vector<int>adj[n];

         unordered_map<string,int>umap;

         for(int i=0;i<n;i++){
            adj[i].push_back(i);
         }

         for(auto it :edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
         }

         for(int i=0;i<n;i++){
            vector<int>v=adj[i];
            sort(v.begin(),v.end());
            string ans;
            for(auto it:v){
                ans+=to_string(it)+",";
            }
            umap[ans]++;
         }

         for(auto it:umap){
            int size=count(it.first.begin(),it.first.end(), ',');
            if(size==it.second){
                cnt++;
            }
         }

         return cnt;
       
    }
};