class Solution {
public:
    vector<int> minOperations(string boxes) {
        unordered_set<int>uset;
        
        int n=boxes.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                uset.insert(i);
            }
        }
        

        for(int i=0;i<n;i++){
            int score=0;
            for(auto it:uset){
                score+=abs(it-i);
            }
            ans[i]=score;

        }

        return ans;
        
    }
};