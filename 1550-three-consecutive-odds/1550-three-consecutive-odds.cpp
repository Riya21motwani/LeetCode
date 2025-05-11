class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        vector<int>v(n+1,0);
        for(int i=0;i<n;i++){
            if(arr[i]%2==1){
               v[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(v[i]==1 && v[i+1]==1 && v[i+2]==1){
                return true;
            }
        }
        return false;
    }
};