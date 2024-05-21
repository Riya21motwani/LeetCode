class Solution {
public:
    
    void solve( vector<vector<int>>& ans,vector<int>& v, vector<int>& nums, int ind,int n){
          if(ind==n){
            ans.push_back(v);
              return;
          }
        v.push_back(nums[ind]);
        solve(ans,v,nums,ind+1,n);
        v.pop_back();
        solve(ans,v,nums,ind+1,n);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        int n=nums.size();
        solve(ans,v,nums,0,n);
        return ans;
    }
};