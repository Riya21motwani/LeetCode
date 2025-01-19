#include <bits/stdc++.h>
using namespace std;

const int drow[4] = {0, -1, 1, 0};
const int dcol[4] = {1, 0, 0, -1};

class Solution {
public:
    typedef pair<int, pair<int, int>> p;

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        priority_queue<p, vector<p>, greater<p>> pq;

        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        while (!pq.empty()) {
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

           
            if (distance > dis[row][col]) {
                continue;
            }

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    if ((grid[row][col] == 1 && i != 0) || 
                        (grid[row][col] == 2 && i != 3) || 
                        (grid[row][col] == 3 && i != 2) || 
                        (grid[row][col] == 4 && i != 1)) {
                       
                        if (distance + 1 < dis[nrow][ncol]) {
                            dis[nrow][ncol] = distance + 1;
                            pq.push({distance + 1, {nrow, ncol}});
                        }
                    } else {
                      
                        if (distance < dis[nrow][ncol]) {
                            dis[nrow][ncol] = distance;
                            pq.push({distance, {nrow, ncol}});
                        }
                    }
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};
