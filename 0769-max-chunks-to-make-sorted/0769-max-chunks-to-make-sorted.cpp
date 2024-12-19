class Solution {
public:
     
     int findfromi(int ind,vector<int>&arr){
        int n=arr.size();
        int mini=INT_MAX;
        for(int i=ind;i<n;i++){
            mini=min(mini,arr[i]);
        }
        return mini;
     }

    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        int maxi=-1;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);

            int mini=findfromi(i+1,arr);
            if(maxi<mini){
                cnt++;
                maxi=-1;
            }
        }
        return cnt;
    }
};