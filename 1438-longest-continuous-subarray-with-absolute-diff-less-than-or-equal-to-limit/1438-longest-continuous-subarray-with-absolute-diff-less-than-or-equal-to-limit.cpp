class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
       int n=nums.size();
        int i=0;
        int j=0;
        int maxlength=0;
        multiset<int>st;
        while(j<n){
            st.insert(nums[j]);
            while(*st.rbegin()-*st.begin()>limit){
               
               st.erase(st.find(nums[i]));
                i++;
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};