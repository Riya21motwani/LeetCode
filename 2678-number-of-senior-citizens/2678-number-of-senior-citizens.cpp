class Solution {
public:
    
    int canfind( string nw){
        return stoi(nw.substr(11,2));
    }
    
    int countSeniors(vector<string>& details) {
        int n=details.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(canfind( details[i])>60){
                cnt++;
            }
        }
        return cnt;
    }
};