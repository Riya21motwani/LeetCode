class Solution {
public:

     bool isVowel(char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

  
    long long countOfSubstrings(string word, int k) {
      int n=word.size();
      unordered_map<char,int>umap;
      int constcnt=0;
      vector<int>consonant(n,n);
      int constidx=n;
       long long res=0;

      for(int i = n-1; i >=0; i--) {
            consonant[i] = constidx;
            if(!isVowel(word[i])) { 
                constidx = i;
            }
        }


      int i=0;
      int j=0;

      while(j<n){
            
            if(isVowel(word[j])){
                umap[word[j]]++;
            }else{
                constcnt++;
            }

            while(constcnt>k){
                if(isVowel(word[i])){
                    umap[word[i]]--;
                    if(umap[word[i]]==0){
                        umap.erase(word[i]);
                    }
                }else{
                    constcnt--;
                }
                i++;
            }
            while(i<n && umap.size()==5 && constcnt==k){
                res+=(consonant[j]-j);
                 if(isVowel(word[i])){
                    umap[word[i]]--;
                    if(umap[word[i]]==0){
                        umap.erase(word[i]);
                    }
                }else{
                    constcnt--;
                }
                i++;

            }
            j++;
      }



return res;
    }
};