class Solution {
public:

    bool iscycle(int node, vector<vector<int>>& graph, vector<bool>&vis,vector<bool>&path){
        vis[node]=true;
        path[node]=true;
        for(auto it:graph[node]){
            if(!vis[it] && iscycle(it,graph,vis,path)){
                return true ;
            }
            else if(vis[it]==true  && path[it]==true){
                return true;
            }
        }
        path[node]=false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<bool>vis(n,0);
         vector<bool>path(n,0);
         vector<int>res;

         for(int i=0;i<n;i++){
            if(!vis[i]){
             iscycle(i,graph,vis,path);   
            } 
         }

         for(int i=0;i<n;i++){
            if(path[i]!=true){
                res.push_back(i);
            }
         }
        return res;
    }
};