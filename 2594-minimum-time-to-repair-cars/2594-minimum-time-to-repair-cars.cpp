class Solution {
public:

    bool possible(long long mid, vector<int>& ranks, int cars ){
        int total=0;
        for(int i=0;i<ranks.size();i++){
            total+=sqrt(mid/ranks[i]);
        }

        return total>=cars;
    }

     int maximum( vector<int>& ranks){
        int  maxi=0;
        for(int i=0;i<ranks.size();i++){
            maxi=max(maxi,ranks[i]);
        }
        return maxi;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long ans=0;
        long long  l=1;
        long long  h=(long long)maximum(ranks)*cars*cars;

        while(l<=h){
            long long mid=(l+h)/2;

            if(possible(mid,ranks,cars)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};