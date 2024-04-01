class Solution {
public:
    int lengthOfLastWord(string s) {
        int ind=s.find_last_not_of(' ')+1;
        s.erase(ind);
        int last_word_beforespace= s.find_last_of(' ');
        return  last_word_beforespace==string::npos?s.length() :s.length()-last_word_beforespace-1;
    }
};