class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>v(n-1,0);
        int maxi=INT_MIN;
        int mini=INT_MAX;
        priority_queue<int>pqmax;
        priority_queue<int, vector<int>, greater<int>> pqmin;
        int sum=weights[0]+weights[n-1];
        for(int i=0;i<n-1;i++){
            sum=(weights[i]+weights[i+1]);
            pqmax.push(sum);
            pqmin.push(sum);
        }
        int sum1=0;
        int sum2=0;
        int p=k;
        
        while(!pqmax.empty() && k-1 > 0){
            sum1+=pqmax.top();
            pqmax.pop();
            k--;
        }

        while(!pqmin.empty()  && p-1>0){
            sum2+=pqmin.top();
            pqmin.pop();
            p--;
        }

        return sum1-sum2;

    }
};