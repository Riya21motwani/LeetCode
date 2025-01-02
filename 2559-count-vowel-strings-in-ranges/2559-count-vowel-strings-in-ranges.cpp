class Solution {
public:

    bool f(string &word) {
        int n = word.size();
        if (n == 0) return false; // Handle empty words
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(word[0]) && vowels.count(word[n-1]);
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
       vector<int>newarr(n,0);
       int m=queries.size();
       vector<int>res(m,0);

       if(f(words[0])==true){
        newarr[0]=1;
       }

       for(int i=1;i<n;i++){
        if(f(words[i])==true){
            newarr[i]=newarr[i-1]+1;
        }else{
            newarr[i]=newarr[i-1];
        }
       }

       for(int i=0;i<queries.size();i++){
        int l=queries[i][0];
        int r=queries[i][1];

        if(l==0){
            res[i]=newarr[r];
        }else{
            res[i]=newarr[r]-newarr[l-1];
        }

       }

    return res;

    }
};