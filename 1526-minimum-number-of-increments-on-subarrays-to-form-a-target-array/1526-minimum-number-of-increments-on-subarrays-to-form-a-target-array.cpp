class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int prev=-1;
        int op=0;
        int curr=0;
        vector<int>initial(n,0);
        for(int i=0;i<n;i++){
            if(prev!=-1 && target[i]>target[prev]){
                op+=(target[i]-target[prev]);
            }
            else if(prev==-1){
                op=target[0];
            }
            prev=i;
        }
        return op;
    }
};