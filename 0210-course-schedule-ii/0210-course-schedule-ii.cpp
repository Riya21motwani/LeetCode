class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>in(numCourses,0);
        unordered_map<int,vector<int>>adj;
        
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
            in[a]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
                 ans.push_back(i);
            }
        }
        int cnt=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
           
            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                     ans.push_back(it);
                }
            }

        }

        if(cnt!=numCourses){
            return {};
        }


        return ans;
        
    }
};