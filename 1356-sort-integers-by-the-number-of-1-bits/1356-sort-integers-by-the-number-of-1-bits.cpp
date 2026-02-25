class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int val=arr[i];
            int cnt=__builtin_popcount(val);
            mp[cnt].push_back(val);
            
        }
        vector<int>ans;
        for(auto it:mp){
            for(auto j:it.second){
                ans.push_back(j);
            }
        }

        return ans;
    }
};