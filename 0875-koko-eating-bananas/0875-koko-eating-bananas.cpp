class Solution {
public:
    
   int isPossible(vector<int>& piles, int h,int k){
    int t=0;
    for(int i=0;i<piles.size();i++){
        if(piles[i]%k==0)t+=piles[i]/k;
     else t+=(piles[i]/k)+1;
    }
    return t;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int ans=0;
        int s=1;
        int e=piles[piles.size()-1];
        while(e>=s){
            int mid=e-(e-s)/2;
            if(isPossible(piles,h,mid)<=h){
                e=mid-1;
                ans=mid;
            }
            else s=mid+1;
        }
        return ans;
    }
};