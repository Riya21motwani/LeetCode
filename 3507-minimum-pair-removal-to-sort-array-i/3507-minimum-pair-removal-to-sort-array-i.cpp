class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        while(!is_sorted(nums.begin(),nums.end())){

            int minsum=INT_MAX;
            int idx=-1;
            for(int i=0;i<nums.size()-1;i++){
                int sum=nums[i]+nums[i+1];
                if(sum<minsum){
                    minsum=sum;
                    idx=i;
                }
            }
            vector<int>v;
            for(int i=0;i<nums.size();i++){
                if(i==idx){
                    v.push_back(nums[i+1]+nums[i]);
                    i++;
                }else{
                    v.push_back(nums[i]);
                }
            }
            nums=v;
            cnt++;
            
        }
        return cnt;
    }
};