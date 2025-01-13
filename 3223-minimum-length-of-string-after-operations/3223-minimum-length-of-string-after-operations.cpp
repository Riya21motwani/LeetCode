class Solution {
public:
    int minimumLength(string s) {
        int ans=0;
        int n=s.size();
        vector<int>arr(26,0);

        for(int i=0;i<s.size();i++){
            char ch=s[i];

            arr[ch-'a']++;
        }

        for(int i=0;i<26;i++){
            int freq=arr[i];

            if(freq!=0 && freq%2==0){
                ans+=2;
            }else if(freq%2==1){
                ans+=1;
            }
        }
        return ans;

    }
};