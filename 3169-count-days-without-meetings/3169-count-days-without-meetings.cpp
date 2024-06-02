class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int last=1;
        int ans=0;
        sort(meetings.begin(),meetings.end());
          for(int i=0;i<n;i++){
             int s=meetings[i][0];
              int e=meetings[i][1];
              if(i==0){
                ans+=s-last;
              }else{
                  if(s>last){
                  ans+=s-last-1;
                  }
              }
              last=max(last,e);
         }
        if(days>last){
               ans+=days-last;
        }
        return ans;
       }
};