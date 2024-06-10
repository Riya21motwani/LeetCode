class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>correctheight=heights;
        int cnt=0;
        sort(correctheight.begin(),correctheight.end());
        for(int i= 0;i<n;i++){
            if(correctheight[i]!=heights[i]){
              cnt++;
            }
        }
        return cnt;
    }
};