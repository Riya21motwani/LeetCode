class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        vector<int>prefixxor(arr.begin(),arr.end());
        
        prefixxor.insert(prefixxor.begin(),0);
        int n=prefixxor.size();
        for(int i=1;i<n;i++){
               prefixxor[i]^=prefixxor[i-1];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
               if(prefixxor[i]==prefixxor[k]){
                        cnt+=k-i-1;
               }
            }
        }
        return cnt;
    }
};