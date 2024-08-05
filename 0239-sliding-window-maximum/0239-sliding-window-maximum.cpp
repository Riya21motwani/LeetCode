class Solution {
public:
    typedef pair<int,int>p;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        deque<int>dq;
        
        while(i<n){
            while(!dq.empty() &&  dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
             if(i>=k-1){
                 ans.push_back(nums[dq.front()]);
             }
            i++;
        }
        
        return ans;
       
    }
};