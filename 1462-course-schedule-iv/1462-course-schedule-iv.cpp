class Solution {
public:
  
  vector<int> dfs( int numCourses,  unordered_map<int,vector<int>>&adj, vector<int>&indegree , queue<int>&q  , vector<int>&ans){
       for(int i=0;i<numCourses;i++){
           if(indegree[i] ==0){
                  q.push(i);
           }
       }
       
      int cnt=0;
       
      while(!q.empty()){
           int node=q.front();
           q.pop();
          cnt++;
           ans.push_back(node);
           for(auto it:adj[node]){
               indegree[it]--;
              if(indegree[it]==0){
                      q.push(it);
              }
           }
       }
       
       return ans;
       
   }


 
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        int n=queries.size();
        vector<bool>res(n,false);
        vector<int>indegree(numCourses,0);

        if(prerequisites.size()==0){
            return res;
        }

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans;
        queue<int>q;
        vector<int>topo=dfs( numCourses, adj, indegree , q , ans );
        unordered_map<int,int>umap;

        for(int i=0;i<topo.size();i++){
            umap[topo[i]]=i;
        }


        for(int i=0;i<n;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            int t=umap[u];
            int k=umap[v];
            if(t<k){
                res[i]=true;
            }

             
        }

        return res;
    }
};