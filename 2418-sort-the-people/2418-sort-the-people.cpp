class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>umap;
        int n=heights.size();
        for(int i=0;i<n;i++){
            umap[heights[i]]=names[i];
        }
       
        vector<string>ans;
        for(auto it:umap){
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};