#include <ranges>
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        int n=arr.size();

        for(int i=0;i<n;i++){
            while(true){
                
                int ind=-1;
                int smallval=arr[i];
                for(int j=i+1;j<n;j++){
                    if(abs(arr[i]-arr[j])<=limit && arr[j]<smallval){
                        ind=j;
                        smallval=arr[j];
                    }
                }
                if(ind!=-1){
                    swap(arr[i],arr[ind]);
                }else{
                    break;
                }

            }
        }
        return arr;
    }
};
