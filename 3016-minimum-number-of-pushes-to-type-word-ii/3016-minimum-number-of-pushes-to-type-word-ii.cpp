class Solution {
public:
    int minimumPushes(string word) {
       
        vector<int> frequency(26, 0);

       
        for (char& c : word) {
            ++frequency[c - 'a'];
        }

        
        sort(frequency.rbegin(), frequency.rend());

        int total = 0;

        
        for (int i = 0; i < 26; ++i) {
            if (frequency[i] == 0) break;
            total += (i / 8 + 1) * frequency[i];
        }

        return total;
    }
};