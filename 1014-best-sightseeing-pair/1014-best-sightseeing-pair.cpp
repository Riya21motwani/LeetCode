class Solution {
public:

    
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxi=INT_MIN;
        vector<int>a1(n);
        vector<int>a2(n);
        int maxi2=a2[0];

        

        
        for(int i=0;i<n;i++){
            a1[i]=values[i]-i;
            a2[i]=values[i]+i;
        }
        for(int i=1;i<n;i++){
            maxi2=max(maxi2,a2[i-1]);
            maxi= max(maxi,maxi2+a1[i]);
        }




        return maxi;
        
    }
};