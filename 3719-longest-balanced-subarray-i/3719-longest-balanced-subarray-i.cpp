class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int maxi=0;
        unordered_map<int,int>odd;
        unordered_map<int,int>eve;
        
        for(int i=0;i<n;i++){
            odd.clear();
            eve.clear();
            
            for(int j=i;j<n;j++){
                if(nums[j] % 2==1){
                    odd[nums[j]]++;
                }
                else{
                    eve[nums[j]]++;
                }
                if(odd.size()==eve.size()){
                    maxi=max(maxi,(j-i+1));
                }
            }
        }
        return maxi;
    }
};