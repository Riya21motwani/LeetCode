class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        vector<int>arr(26,0);
        unordered_set<int>uset;
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int freq=arr[i];
            while(freq>0 && uset.find(freq)!=uset.end()){
                freq--;
                ans++;
            }
            uset.insert(freq);
        }
        return ans;
    }
};