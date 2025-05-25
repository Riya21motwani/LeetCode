class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int cnt=0;
        int m=queries.size();
        sort(queries.begin(),queries.end());
        priority_queue<int>pqmax;
        priority_queue<int,vector<int>,greater<int>>pqmin;
        int j=0;

        for(int i=0;i<n;i++){
            while(j<m && queries[j][0]==i){
                pqmax.push(queries[j][1]);
                j++;
            }
            nums[i]-=pqmin.size();
            while(nums[i]>0 && !pqmax.empty() && pqmax.top()>=i){
                int last=pqmax.top();
                pqmax.pop();
                cnt++;
                pqmin.push(last);
                nums[i]--;
            }

            if(nums[i]>0){
                return -1;
            }

            while(!pqmin.empty() && pqmin.top()<=i){
                pqmin.pop();
            }
        }

        return m-cnt;
    }
};