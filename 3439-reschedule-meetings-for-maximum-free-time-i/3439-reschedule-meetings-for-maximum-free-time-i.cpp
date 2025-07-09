class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>ans;
        ans.push_back( startTime[0]-0);
       for(int i=1;i<n;i++){
        ans.push_back( startTime[i]-endTime[i-1]);

       }
       ans.push_back(eventTime-endTime[n-1]);

        int i=0;
        int j=0;
        int size=k+1;
        int cnt=0;
        int maxi=0;
int sum=0;
int m=ans.size();
        while(j<m){
           
            sum+=ans[j];
            
          
            while( j-i+1>size){
                
                sum-=ans[i];
                i++;
            }
            j++;
              maxi=max(maxi,sum);
        }
return maxi;
    }
};