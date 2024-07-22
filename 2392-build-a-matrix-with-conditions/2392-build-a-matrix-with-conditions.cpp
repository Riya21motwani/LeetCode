class Solution {
public:
    
    vector<int>toposort( vector<vector<int>>& edges , int &k){
        unordered_map<int,vector<int>>adj;
         vector<int>indegree(k+1,0);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        
        
        queue<int>q;
        
        int cnt=0;
        
        for(int i=1;i<=k;i++){
            if(indegree[i]==0){
                q.push(i);
                cnt++;
            }
        }
        
        
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    cnt++;
                }
            }
        }
      
        if(cnt!=k){
            return {};
        }
        
        
        return topo;
        
    }
    
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
     
        vector<int>toporow=toposort( rowConditions,k);
        vector<int>topocol=toposort( colConditions,k);
        if(toporow.size()==0 || topocol.size()==0){
            return {};
        }
        vector<vector<int>>matrix(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(toporow[i]==topocol[j]){
                    matrix[i][j]=toporow[i];
                }
            }
        }
        
        return matrix;

    }
};