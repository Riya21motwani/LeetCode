class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tgas=0;
        int tcost=0;
        for(int i=0;i<n;i++){
            tgas+=gas[i];
            tcost+=cost[i];
        }
        if(tcost>tgas){
            return -1;
        }
        int total=0;
        int res=0;
        for(int i=0;i<n;i++){
           total+=(gas[i]-cost[i]);
           if(total<0){
            total=0;
            res=i+1;
           }
        }

        return res;
    }
};