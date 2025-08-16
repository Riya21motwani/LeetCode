class Solution {
public:

    typedef pair<int,int>p;
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int cnt=0;
        while(i<n && j<n){
            if(nums[j]>nums[i]){
                cnt++;
                i++;
                j++;

            }else{
                j++;
            }
        }

        return cnt;
    }
};