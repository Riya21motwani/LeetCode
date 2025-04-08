class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        deque<int>q;
        int cnt=0;
        int t=1;
        for(int i=0;i<n;i++){
            q.push_back(nums[i]);
        }
        for(int i=0;i<n-1;i++){
            
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    int p=3;
                    
                    while(p>0 && !q.empty()){
                        q.pop_front();
                        p--;
                    }
                    i=t*3-1;
                    t++;
                    cnt++;
                    break;
                }
                
            }
        }
            return cnt;
        }
};