class Solution {
public:
    
    void find( int ind, int target,   vector<int>&ds, vector<vector<int>>&ans, vector<int>& candidates, int n){
         if(ind==n){
                if(target==0){
                       ans.push_back(ds);
                }
             return;
         }
        
        if(candidates[ind]<=target){
              ds.push_back(candidates[ind]);
             find(ind,target-candidates[ind],ds,ans,candidates,n);
            ds.pop_back();
            
        }
        
        find(ind+1,target,ds,ans,candidates,n);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n= candidates.size();
        vector<vector<int>>ans;
        vector<int>ds;
        find(0,target,ds,ans,candidates,n);
        return ans;
        
        
    }
    
};