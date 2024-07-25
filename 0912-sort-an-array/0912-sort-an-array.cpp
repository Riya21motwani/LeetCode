class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>res;
       priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i] });
        }
        while(!pq.empty()){
           
            int element=pq.top();
            pq.pop();
            res.push_back(element);
        }
        
        return res;
    }
};