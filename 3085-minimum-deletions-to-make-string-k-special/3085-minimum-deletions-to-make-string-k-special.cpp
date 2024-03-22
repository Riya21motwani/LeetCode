class Solution {
public:
    int minimumDeletions(string word, int k) {
       vector<int> arr(26, 0);
        for(auto i : word) arr[i - 'a']++;
        int mini = INT_MAX;
        for(int i = 0; i < 26; i++){
            int del = 0;
           
            
            for(int j = 0; j < 26; j++){
                if(i==j)continue;
                if(arr[j] < arr[i]) del += arr[j];           
                else if(arr[j] - arr[i] <= k) continue;   
                else del += arr[j] - arr[i] - k;           
            }
            mini = min(mini, del);
        }
        return mini;
    }
};