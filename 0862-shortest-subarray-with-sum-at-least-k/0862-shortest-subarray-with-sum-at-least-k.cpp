class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> deq;
        vector<long long> presum(n, 0);  
        int result = INT_MAX;
        int j = 0;
        while (j < n) {
            if (j == 0)
                 presum[j] = nums[j];
            else
                 presum[j] =  presum[j - 1] + nums[j];
            
          
            if ( presum[j] >= k) 
                result = min(result, j + 1);
            
          
            while (!deq.empty() &&  presum[j] -  presum[deq.front()] >= k) {
                result = min(result, j - deq.front()); 
                deq.pop_front(); 
            }

           
            while (!deq.empty() &&  presum[j] <=  presum[deq.back()]) {
                deq.pop_back();
            }

            
            deq.push_back(j);

            j++;  
        }

     
        return result == INT_MAX ? -1 : result;
    }
};