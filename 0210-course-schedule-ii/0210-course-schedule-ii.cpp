class Solution {
public:
    
   bool dfs( int numCourses,  unordered_map<int,vector<int>>&adj, vector<int>&indegree , queue<int>&q  , vector<int>&ans){
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
       if(cnt==numCourses){
           return true;
       }
        
        return false;
       
   }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
vector<int>indegree(numCourses,0);
        for(auto it:prerequisites){
            int a=it[0];
            int b=it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        vector<int>ans;
        queue<int>q;
      if((dfs( numCourses, adj, indegree , q , ans )==true)){
          return ans;
      }
        
        return {};
    }
};