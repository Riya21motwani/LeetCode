class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>uset(bank.begin(),bank.end());
        unordered_set<string>vis;
        int n=startGene.size();

        int cnt=0;

        queue<string>q;
        q.push(startGene);
        vis.insert(startGene);

     

        while(!q.empty()){
            int n=q.size();
            
            
        while(n--){
            string temp=q.front();
            q.pop();
           
            if(temp==endGene){
                return cnt;
            }
        for(char ch:"ACGT"){
            for(int i=0;i<temp.size();i++){
                string curr=temp;
                curr[i]=ch;
                if(vis.find( curr)==vis.end() && uset.find(curr)!=uset.end()){
                    q.push(curr);
                    vis.insert(curr);
                }
            }
        }
        }
        cnt++;
        }
        return -1;

    }
};