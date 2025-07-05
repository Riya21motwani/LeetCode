class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int>v(501,0);
        for(int i=0;i<arr.size();i++){
            int el=arr[i];
            int ind=el;
            v[ind]++;
        }
        int ans=-1;
        for(int i=0;i<=500;i++){
            if(v[i]==i){
                ans=i;
            }
        }
        if(ans==0){
            return -1;
        }
        return ans;
    }
};