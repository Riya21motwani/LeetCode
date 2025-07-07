class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
       sort(events.begin(),events.end());
       int ans=0;
       int s=events[0][0];
        priority_queue<int,vector<int>,greater<int>>pq;
       int i=0;
      
       int n=events.size();
       while(i<n || !pq.empty()){
        
        while(i<n && events[i][0]==s){
            pq.push(events[i][1]);
            i++;
        }
        s++;
        if(!pq.empty()){
            pq.pop();
            ans++;
        }
        while(!pq.empty() && s>pq.top()){
            pq.pop();
        }
       }

       return ans;
    }
};