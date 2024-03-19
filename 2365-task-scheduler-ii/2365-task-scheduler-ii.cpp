class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long  day = 0;
        
        int n = tasks.size();
        map<long long,long long> last;
        for (int i = 0; i < n; i ++) {
            if (last.find(tasks[i]) == last.end()) {
                day ++;
                last[tasks[i]] = day;
                continue;
            }
            
           long long last_done_day = last[tasks[i]];
            day = max (day+1, last_done_day + space + 1);
            last[tasks[i]] = day;
        }
        
        return day;
    }
};