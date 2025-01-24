class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_map<int, unordered_set<int>> adj;

      
        vector<int> indegree(n, 0);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            adj[u].insert(v);
            adj[v].insert(u);
            indegree[u]++;
            indegree[v]++;
        }

        int maxi = 0;

      
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = indegree[i] + indegree[j];
               
                if (adj[i].count(j)) {
                    rank--;
                }
                maxi = max(maxi, rank);
            }
        }

        return maxi;
    }
};
