class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>deg(n,0);
        for(auto it:roads){
            deg[it[0]]++;
            deg[it[1]]++;
        }
        sort(deg.begin(),deg.end());
        long long sum=0;
        long long element=1;
        for(long long i=0;i<n;i++){
            sum+=(deg[i]*element);
            element++;
        }
        return sum;
    }
};