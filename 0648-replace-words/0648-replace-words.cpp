class Solution {
public:
    
    string findstring(string words ,unordered_set<string>&uset ){
            for(int i=1;i<words.size();i++){
                string root=words.substr(0,i);
                if(uset.find(root)!=uset.end()){
                       return root;
                }
            }
        return words;
    }
    
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>uset;
        for(int i=0;i< dictionary.size();i++){
           uset.insert(dictionary[i]);
        }
        
        stringstream ss(sentence);
        string words;
        string ans;
        
        while(getline(ss,words,' ')){
              ans+=findstring(words,uset) +' ';
        }
        ans.pop_back();
        return ans;
        
        
    }
};