class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long cmass=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int i=0;i<asteroids.size();i++){
            if(cmass>=asteroids[i]){
               cmass+=(1LL* asteroids[i]);
            }else{
                return false;
            }
        }
        return true;
    }
};