class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        unordered_map<char,int>umap;

        for(int i=0;i<tasks.size();i++){
            umap[tasks[i]]++;
        }

        for(auto it:umap){
            pq.push(it.second);
        }
        int cnt=0;
        while(!pq.empty()){

          
            vector<int>temp;
            
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                int f=pq.top();
                f--;
                pq.pop();
                temp.push_back(f);
            }
            
            }

           

            for(auto it:temp){
                if(it>0){
                    pq.push(it);
                }
            }

             if(pq.empty()){
                cnt+=temp.size();
            }else{
                cnt+=(n+1);
            }
            

        
        }
        return cnt;

    }
};