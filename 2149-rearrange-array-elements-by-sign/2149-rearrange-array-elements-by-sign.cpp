class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>a1;
        vector<int>a2;
        
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                a1.push_back(nums[i]);
            }else{
                a2.push_back(nums[i]);
            }
        }
        int k=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(i%2==0 && j<n/2){
                nums[i]=a1[j];
                j++;
            }else if(i%2==1 && k< n/2){
                nums[i]=a2[k];
                k++;
            }
        }
        return nums;
    }
};