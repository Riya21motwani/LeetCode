class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string >st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        while(!q.empty()){

            string word=q.front().first;
            int cnt=q.front().second;
            q.pop();
            if(word==endWord)return cnt;
            for(int i=0;i<word.size();i++){
               int originalletter=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,cnt+1});
                        st.erase(word);
                       
                    }
                }
                word[i]=originalletter;
            }
            
        }
       
        return 0;
        
        
    }
};