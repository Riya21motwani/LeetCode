class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        vector<char>v(n);
        char minchar=s[n-1];
        v[n-1]=s[n-1];
        //s1
        for(int i=n-2;i>=0;i--){
            if(s[i]>v[i+1]){
                v[i]=v[i+1];
            }else{
                v[i]=s[i];
            }
        }

        //s2;
        int i=0;
        string t="";
        string p="";
        while(i<n){
            t.push_back(s[i]);
            char minimumcharfromlast=s[i];
            if(i+1<n){
                minimumcharfromlast=v[i+1];
            }

            while(!t.empty() && t.back() <=minimumcharfromlast){
                p+=t.back();
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            p+=t.back();
            t.pop_back();
        }

        return p;

    }
};