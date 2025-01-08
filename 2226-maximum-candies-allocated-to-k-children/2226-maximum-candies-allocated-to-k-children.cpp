class Solution {
public:

    int mini(vector<int>& candies){
        int m=INT_MIN;
        int n =candies.size();

        for(int i=0;i<n;i++){
            m=max(m,candies[i]);
        }

        return m;
    }

    long long ischeck(int val, vector<int>& candies){
        int n=candies.size();
        long long res=0;
        for(int i=0;i<n;i++){
            res+=(long long)candies[i]/val;
        }
        return res;
    }
     

    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int l=1;
        int h=mini(candies);
        int ans=0;

        while(l<=h){
            int mid=(l+h)/2;

            if(ischeck(mid,candies)>=k){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }

        return ans;
    }
};