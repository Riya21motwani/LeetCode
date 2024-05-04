class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0,j=n-1,sum=0,cnt=0;
        sort(people.begin(),people.end());
        
        while(i<=j){
         
            if(people[i]+people[j]<=limit || i==j){
               i++;j--;
                cnt++;
            }
            else if(people[j]<=limit){

            cnt+=1;;
                j--;
            }
            
        }
        
        return cnt;
    }
};