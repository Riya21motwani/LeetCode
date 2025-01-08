class Solution {


public:


    bool suf(string &word1,string &word2){
         int n1=word1.size();
        int n2=word2.size();
        int i=n1-1;
        int j=n2-1;

        while(i>=0 && j>=0){
            while(word1[i]==word2[j]){
                i--;
                j--;
                if(i==-1){
                    return true;
                }
            }
            return false;
        }
        return false;
    }

    bool pre(string &word1,string &word2){
        int n1=word1.size();
        int n2=word2.size();

        int i=0;
        int j=0;

        while(i<n1 &&j<n2){
            while(word1[i]==word2[j]){
                i++;
                j++;
                if(i==n1){
                    return true;
                }
            }
            return false;
            
        }
        return false;
    }

    bool ispresuf(string &word1,string &word2){
        int n1=word1.size();
        int n2=word2.size();
        if(n1>n2){
            return false;
        }

        return pre(word1,word2)&& suf(word1,word2);
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int cnt=0;
        for(int j=1;j<n;j++){
            for(int i=j-1;i>=0;i--){
                if(ispresuf(words[i],words[j])==true){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};