class Solution {
public:
    
    bool bfs(vector<int>&ans, vector<int>&indegree,  unordered_map<int,vector<int>>&adj , int numCourses){
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
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
        if(cnt==numCourses)return true;
        return false;
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
       
       
      for(auto it: prerequisites){
            int a=it[0] ;
            int b=it[1];
          //b->a
            adj[b].push_back(a);
          indegree[a]++;
          
        }
        
        
        if( bfs(ans,indegree,adj,numCourses)==true){
            return ans;
        }
        return {};
        
    }
};