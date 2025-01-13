class Solution {
public:
    
    int canfind( vector<int>& nums, int n , int idx){
        int sum=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]+sum<=idx){
                sum+=nums[i];
            }else{
                cnt++;
                sum=nums[i];
            }
        }
        return cnt;
    }
    int sum(vector<int>& nums){
        int summ=0;
        for(int i=0;i<nums.size();i++){
            summ+=nums[i];
        }
        return summ;
    }
    
    
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        
        int l=*max_element(nums.begin(),nums.end());
        int h=sum(nums);
        int ans=-1;
        while(l<=h){
            int mid=(l+h)/2;
            
             if(canfind(nums,n,mid) <=k){
                ans=mid;
                h=mid-1;
            }else if(canfind(nums,n,mid) >k){
               l=mid+1;
            }
        }
        
        return ans;
    }
};