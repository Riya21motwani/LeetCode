class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>res;
        for(int i=0;i<=11;i++){
            for(int j=0;j<=59;j++){
                string hr=to_string(i);
                if(__builtin_popcount(i)+__builtin_popcount(j) == turnedOn){
                    string min=(j< 10 ? "0" : "")+ to_string(j);
                    res.push_back(hr+ ":" + min);
                }
            }
        }
        return res;
    }
};