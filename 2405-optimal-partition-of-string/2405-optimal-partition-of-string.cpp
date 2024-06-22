class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int start=0;
        int cnt=0;
       vector<int>arr(26,-1);
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(arr[ch-'a']>=start){
                start=i;
                cnt++;
            }
            arr[ch-'a']=i;
        }
        return cnt+1;
    }
};