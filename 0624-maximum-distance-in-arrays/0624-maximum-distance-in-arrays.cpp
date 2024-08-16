class Solution {
public:
 
    
    
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=arrays[0].front();
        int maxi=arrays[0].back();
        int n=arrays.size();
        int res=INT_MIN;
        for(int i=1;i<n;i++){
            int diff=max(abs(arrays[i].front()-maxi), abs(arrays[i].back()-mini));
            res=max(res,diff);
            mini=min(mini,arrays[i].front());
            maxi=max(maxi,arrays[i].back());
        }
        
        return res;
    }
};