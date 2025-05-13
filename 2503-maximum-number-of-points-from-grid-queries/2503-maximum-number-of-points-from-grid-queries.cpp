class Solution {
public:
    typedef pair<int, int> pii;

    vector<int> f(vector<vector<int>>& grid, vector<pair<int,int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(q.size(), 0);

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        vector<vector<int>> vis(n, vector<int>(m, 0));
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

        vis[0][0] = 1;
        pq.push({grid[0][0], {0, 0}});
        int cnt = 0, ind = 0;

        while (!pq.empty() && ind < q.size()) {
            int value = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;

            if (value < q[ind].first) {
                pq.pop();
                cnt++;

                for (int i = 0; i < 4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];

                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol]) {
                        vis[nrow][ncol] = 1;
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
            } else {
                ans[q[ind].second] = cnt;
                ind++;
            }
        }

        // In case some queries are larger than all reachable values
        while (ind < q.size()) {
            ans[q[ind].second] = cnt;
            ind++;
        }

        return ans;
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<pair<int, int>> q;
        for (int i = 0; i < k; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        return f(grid, q);
    }
};
