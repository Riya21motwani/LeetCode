class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int cnt=0;
        sort(meetings.begin(),meetings.end());
       int mini=INT_MAX;
       int maxi=INT_MIN;

        for(int i=0;i<meetings.size();i++){
           int s=meetings[i][0];
           int e=meetings[i][1];
           if(s>maxi && maxi!=INT_MIN){
            cnt+=(s-maxi-1);
           }
           mini=min(mini,s);
           maxi=max(maxi,e);
        }

        return  (mini-1 + days-maxi) +cnt;

        
    }
};