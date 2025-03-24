class Solution {
public:

    int f(int i, int j, vector<int>& g, vector<int>& s){
        int n=g.size();
        int m=s.size();

        if(i==n || j==m){
            return 0;
        }

        int take=0;
        int notake=0;
        if(s[j]>=g[i]){
            take=1+f(i+1,j+1,g,s);
        }else{
            notake=f(i+1,j,g,s) +f(i,j+1,g,s);
        }

        return take+notake;
    }


    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        return f(0,0,g,s);

    }
};