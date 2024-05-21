class Solution {
public:
    
    void solve(int ind, vector<int>& nums,int n,int &subsetcnt ,vector<int>& curr){
         if(ind==n  ){
             if(curr.size()>1){
             int cnt=0;
             for(int i=0;i<curr.size();i++){
                  cnt^=curr[i];
             }
             subsetcnt+=cnt;
             }
         return;
         }
       
        curr.push_back(nums[ind]);
        solve(ind+1,nums,n,subsetcnt,curr);
        curr.pop_back();
        solve(ind+1,nums,n,subsetcnt,curr);
    }
    
    
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int subsetcnt=0;
        for(int i=0;i<n;i++){
               subsetcnt+=nums[i];
        }
        
        vector<int>curr;
        solve(0,nums,n,subsetcnt,curr);
        return subsetcnt;
    }
};  