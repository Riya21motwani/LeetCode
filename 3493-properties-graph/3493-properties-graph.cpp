#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
   
    int countCommon(const vector<int>& prop1, const vector<int>& prop2) {
        unordered_map<int, int> umap;
        
       
        for (int num : prop1) {
            umap[num]++;
        }

        int count = 0;

        
        for (int num : prop2) {
            if (umap[num] > 0) {  
                count++;
                umap[num] = 0;     
            }
        }
        
        return count;
    }

   
    int findParent(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = findParent(parent[x], parent);
        }
        return parent[x];
    }

    
    void unionSet(int x, int y, vector<int>& parent, vector<int>& rank) {
        int rootX = findParent(x, parent);
        int rootY = findParent(y, parent);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (countCommon(properties[i], properties[j]) >= k) {
                    unionSet(i, j, parent, rank);
                }
            }
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (findParent(i, parent) == i) {
                components++;
            }
        }

        return components;
    }
};
