class Solution {
public:
   set< vector<int>>ans;
    void find(int ind,int n, vector<int>&ds ,vector<int>& nums){
         
        if(ind==n){
            if(ds.size()<=1)return ;
            for(int i=1;i<ds.size();i++){
                 if(ds[i]<ds[i-1]){
                      return;
                 }
            }
            
            ans.insert(ds);
            return;
        
        }
        
        ds.push_back(nums[ind]);
        find(ind+1,n,ds,nums);
        ds.pop_back();
        find(ind+1,n,ds,nums);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>ds;
        find(0,nums.size(),ds,nums);
        vector<vector<int>>res;
        for(auto it:ans){

        res.push_back(it);
     }
        return res;
    }
};