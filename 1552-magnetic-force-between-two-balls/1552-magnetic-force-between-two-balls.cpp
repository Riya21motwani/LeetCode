class Solution {
public:
    
    bool isvalid(int f, vector<int>& position, int m){
        int prev=position[0];
        int cnt=1;
        for(int i=1;i<position.size();i++){
            int curr=position[i];
            if(curr-prev>=f){
                cnt++;
                prev=curr;
            }
            if(cnt==m)break;
        }
        if(cnt==m){
            return true;
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int minf=1;
        int res=0;
        int n=position.size();
        int maxf=position[n-1]-position[0];
        while(minf<=maxf){
            int mid=(maxf+minf)/2;
            
            if(isvalid(mid,position,m)){
                res=mid;
                minf=mid+1;
            }else{
                maxf=mid-1;
            }
        }
        return res;
    }
};