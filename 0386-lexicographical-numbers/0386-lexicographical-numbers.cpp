class Solution {
public:

    void dfs(int ind , int n,  vector<int>&ans){
        if(ind>n){
            return;
        }
        ans.push_back(ind);
        for(int i=0;i<=9;i++){
             int num=ind*10+i;
             if(num<=n){
                dfs(num,n,ans);
             }else{
                break;
             }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;

        for(int i=1;i<=9;i++){
            dfs(i,n,ans);
        }

        return ans;
    }
};