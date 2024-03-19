class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int>a(26);
        int time=0;
        for(char &ch:tasks){
         a[ch-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(a[i]>0){
                pq.push(a[i]);
            }
        }
        
       
        while(!pq.empty()){
           vector<int>extra;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                 int freq=pq.top();
                pq.pop();
                freq--;
                extra.push_back(freq);
                }
            }
            for(auto & f:extra){
              if(f>0){
                    pq.push(f);
              }
            }
            if(pq.empty()){
             time+=extra.size();
            }else{
                time+=n+1;
            }
            
            
        }
        return time;
    }
};