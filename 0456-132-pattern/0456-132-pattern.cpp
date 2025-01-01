class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return false;
        }
        stack<int>st;

        vector<int>a(n);
        a[0]=nums[0];

        for(int i=1;i<n;i++){
            a[i]=min(a[i-1],nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]>=nums[i]){
                continue;
            }
             while(!st.empty() && a[i]>=st.top()){
                st.pop();
            }
            if(!st.empty() && st.top()<nums[i] && a[i]<st.top()){
                return true;
            }
           

            
            st.push(nums[i]);
        }
        return false;
    }
};