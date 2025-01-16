class Solution {
public:

        int f(vector<int>& nums){
            int m=nums.size();
            int ans=0;
            for(int i=0;i<m;i++){
                ans^=nums[i];
            }

            return ans;
        }


    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        if(n1%2==0 && n2%2==1){
            return f(nums1);
        }
        else  if(n2%2==0 && n1%2==1){
            return f(nums2);
        }
        else if(n2%2==1 && n1%2==1){
             return (f(nums2))^(f(nums1));
        }
        
        
        
        return 0;
    }
};