class Solution {
public:


    int t(int ind,vector<int>& days, vector<int>& costs, int n){

        if(ind==n){
            return 0;
        }

        int dayone=costs[0]+t(ind+1,days,costs,n);

        int maxiseven=days[ind]+7;
        int k=ind;
        while(k<n && days[k]<maxiseven){
            k++;
        }
        int dayseven=costs[1]+t(k,days,costs,n);

         int maxithi=days[ind]+30;
         k=ind;
        while(k<n && days[k]<maxithi){
            k++;
        }
        int daythi=costs[2]+t(k,days,costs,n);

        return min({dayone,dayseven,daythi});


    }

    

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        return t(0,days,costs,n);
    }
};