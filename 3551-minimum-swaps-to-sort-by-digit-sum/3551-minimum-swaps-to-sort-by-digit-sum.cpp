class Solution {
public:


     int f(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
  
    typedef pair<int,int>p;
    int minSwaps(vector<int>& nums) {
        priority_queue<pair<int,p>,vector<pair<int,p>>,greater<pair<int,p>>>pq;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int sum=f(nums[i]);
            pq.push({sum,{nums[i],i}});
        }

        int cnt=0;
        int i=0;
        while(!pq.empty()){
            int ind=pq.top().second.second;
            pq.pop();

            if(ind!=i){
                cnt++;
            }
            i++;
        }
        if(cnt%2==1){
            return cnt/2 +1;
        }

        return cnt/2;

    }
};