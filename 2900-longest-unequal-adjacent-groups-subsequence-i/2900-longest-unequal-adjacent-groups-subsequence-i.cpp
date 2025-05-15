class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<pair<int,int>>ans;
        for(int i=0;i<n;i++){
            if(!ans.empty() && groups[i]!=ans.back().first){
                ans.push_back({groups[i],i});
            }
            if(ans.empty()){
                ans.push_back({groups[i],i});
            }
        }

        vector<string>res(n,"");
        for(int i=0;i<n;i++){
            int ind=ans[i].second;
            res[i]=words[ind];
        }

        return res;
    }
};