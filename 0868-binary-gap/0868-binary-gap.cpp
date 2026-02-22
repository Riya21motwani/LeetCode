class Solution {
public:

    string func(int n){
        string ans="";
        while(n>0){
            int bit=n%2;
            ans.push_back(bit);
            n/=2;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }

    int binaryGap(int n) {
        string binary=func(n);

        int i=0;
        int j=0;
        int maxi=0;
        int m=binary.size();
        for(int i=0;i<m;i++){
            if(binary[i]==0)continue;
            for(int j=i+1;j<m;j++){
                if(binary[j]==1){
                    maxi=max(maxi,(j-i));
                    break;
                }
            }
        }
        // if(maxi!=0){
        //     return maxi+1;
        // }
        return maxi;
    }
};