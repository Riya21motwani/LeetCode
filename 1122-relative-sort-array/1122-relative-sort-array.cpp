class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
         vector<int>ans;
        int m=arr2.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr2[i]);
                    arr1[j]=-1;
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<n;i++){
            if(arr1[i]!=-1)ans.push_back(arr1[i]);
        }
        
        return ans;
    }
};