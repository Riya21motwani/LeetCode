class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int unsatisfied=0;
        int maxunsatisf=0;
        for(int i=0;i<minutes;i++){
            unsatisfied+=grumpy[i]*customers[i];
        }
        maxunsatisf=unsatisfied;
        
        int i=0;
        int j=minutes;
        while(j<n){
            unsatisfied+=grumpy[j]*customers[j];
            unsatisfied-=grumpy[i]*customers[i];
            maxunsatisf=max(maxunsatisf,unsatisfied);
            i++;
            j++;
        }
    for(int i=0;i<n;i++){
        if(grumpy[i]==0){
            maxunsatisf+=customers[i];
        }
    }
        return maxunsatisf;
        
    }
};