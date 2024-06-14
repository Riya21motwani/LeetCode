class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,1);//index telling 
        
    
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int previ=0;previ<i;previ++){
                if(nums[i]%nums[previ]==0 && 1+dp[previ]>dp[i]){
                    dp[i]=1+dp[previ];
                    hash[i]=previ;
                }
            }
        }
        int maxi=-1;
        int lastindex=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
        
        
        
        vector<int>temp;
        
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};