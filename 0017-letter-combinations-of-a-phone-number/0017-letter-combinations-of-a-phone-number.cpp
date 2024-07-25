class Solution {
public:
    
    
    void solve(int ind, string digits, string &temp,   vector<string>&res ,  unordered_map<char,string>&umap ){
        int n=digits.size();
        if(ind>=n){
            res.push_back(temp);
            return;
        }
        
        char ch=digits[ind]; // 2
        string str=umap[ch]; // abc
        
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            solve(ind+1,digits,temp,res,umap);
            temp.pop_back();
        }
    }
        
    
        
    
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            
            return {};
        }
        
        unordered_map<char,string>umap;
        
        umap['2']="abc";
        umap['3']="def";
        umap['4']="ghi";
        umap['5']="jkl";
        umap['6']="mno";
        umap['7']="pqrs";
        umap['8']="tuv";
        umap['9']="wxyz";
        
       vector<string>res;
        string temp="";
        solve(0,digits,temp , res,umap);
        
        return res;
        
        
    }
};