class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1){
            if(nums[i]!=nums[i+1]){
                i++;
                continue;
            }
            nums[i]=2*nums[i];
            nums[i+1]=0;
            i=i+2;
        }

        vector<int>a;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                a.push_back(nums[i]);
            }
        }
        for(int i=a.size();i<n;i++){
            a.push_back(0);
        }

        return a;
    }
};