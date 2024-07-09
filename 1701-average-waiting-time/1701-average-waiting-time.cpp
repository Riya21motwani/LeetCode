class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int IdleTime = 0;
        long long WaitTime = 0;

        for (int i = 0; i < customers.size(); i++) {
          
          IdleTime = max(customers[i][0], IdleTime) + customers[i][1];

            
            WaitTime +=IdleTime - customers[i][0];
        }

       
        double average =
            double((double)(WaitTime) / customers.size());
        return average;
        
    }
};