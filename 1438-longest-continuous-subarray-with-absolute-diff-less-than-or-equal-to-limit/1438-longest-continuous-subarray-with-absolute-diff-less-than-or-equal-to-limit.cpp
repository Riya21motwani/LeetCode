class Solution {
public:
    typedef pair<int,int>P;
    int longestSubarray(vector<int>& nums, int limit) {
       int n=nums.size();
        int i=0;
        int j=0;
        int maxlength=0;
        priority_queue<P,vector<P>>maxpq;
        priority_queue<P,vector<P>,greater<P>>minpq;
        while(j<n){
            maxpq.push({nums[j],j});
            minpq.push({nums[j],j});
            while(maxpq.top().first-minpq.top().first>limit){
                i=min(maxpq.top().second,minpq.top().second)+1;
                while(maxpq.top().second<i){
                    maxpq.pop();
                }
                while(minpq.top().second<i){
                    minpq.pop();
                }
            }
            maxlength=max(maxlength,j-i+1);
            j++;
        }
        return maxlength;
    }
};