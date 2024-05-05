class Solution {
public:
    
    void find(int ind,int target,vector<int>& ds,vector<int>& candidates,int n,vector<vector<int>> &ans){
            if(target==0){
                ans.push_back(ds);
                return;
}
             for(int i=ind;i<n;i++){
                 if(i>ind && candidates[i]==candidates[i-1])continue;
                 if(candidates[i]>target)break;
                 if(candidates[i]<=target){
                       
                     ds.push_back(candidates[i]);
                     find(i+1,target-candidates[i],ds,candidates,n,ans);
                     ds.pop_back();

                 }
                 
             
             }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>ds;
        find(0,target , ds , candidates ,n, ans);
        return ans;
        
        
    }
};