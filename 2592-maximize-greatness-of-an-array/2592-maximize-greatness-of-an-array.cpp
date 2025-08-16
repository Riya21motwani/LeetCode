class Solution {
public:

    typedef pair<int,int>p;
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        priority_queue<p,vector<p>,greater<p>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        sort(nums.begin(),nums.end());
        int i=0;
        while(!pq.empty()){
            
            while(!pq.empty() && nums[i]>=pq.top().first){
                pq.pop();
                
            }
            if(!pq.empty() && nums[i]<pq.top().first){
                i++;
                cnt++;
                pq.pop();
            }
            
        }

        return cnt;
    }
};