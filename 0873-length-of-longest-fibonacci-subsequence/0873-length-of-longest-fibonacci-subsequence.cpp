class Solution {
public:
    unordered_map<int, int> umap; 

    int findFibLength(int prev1, int prev2, vector<int>& arr) {
        int n = arr.size();
        if (prev2 >= n) return 0;  

        int nextNum = arr[prev1] + arr[prev2];
        if (umap.find(nextNum) == umap.end()) return 0; 

        int nextIndex = umap[nextNum];
        return 1 + findFibLength(prev2, nextIndex, arr);  
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; 
        umap.clear(); 
        for (int i = 0; i < n; i++) {
            umap[arr[i]] = i; 
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int length = 2 + findFibLength(i, j, arr); 
                maxLength = max(maxLength, length);
            }
        }

        return (maxLength >= 3) ? maxLength : 0; 
    }
};
