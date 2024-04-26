class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int l=0;
        int h=n-1;
        while(l<=h){
          int mid=l+(h-l)/2;
            int find=arr[mid]-mid-1;
            if(find<k){
                 l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return k+h+1;
        
    }
};