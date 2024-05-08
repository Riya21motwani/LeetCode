class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n=score.size();
        vector<string>ans(n);
       unordered_map<int,int>umap;
        for(int i=0;i<n;i++){
            umap[score[i]]=i;
        }
        sort(score.rbegin(),score.rend());
        for(int i=0;i<n;i++){
           if(i==0){
               ans[umap[score[i]]]="Gold Medal";
           }
           else if(i==1){
               ans[umap[score[i]]]="Silver Medal";
           }
           else if(i==2){
               ans[umap[score[i]]]="Bronze Medal";
           }
            else{
               ans[umap[score[i]]]=to_string(i+1);
            }
        }
        return ans;
    }
};