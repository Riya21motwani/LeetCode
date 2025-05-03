class Solution {
public:

    int f( int el , vector<int>& tops, vector<int>& bottoms){
        int n=tops.size();
        int cnt=0;
        int tp=0;
        int btm=0;
        for(int i=0;i<n;i++){
            if(tops[i]!=el && bottoms[i]!=el){
                return INT_MAX;
            }
           else if(bottoms[i]==el){
                 btm++;
            }
            else if(tops[i]==el){
                tp++;
            }
        }

        if(btm+tp<n){
            return INT_MAX;
        }
        return min(n-tp,n-btm);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        
        int finall= min(f(tops[0],tops,bottoms) ,  f(bottoms[0],tops,bottoms) );
        if(finall==INT_MAX){
            return -1;
        }

        return finall-1;
    }
};