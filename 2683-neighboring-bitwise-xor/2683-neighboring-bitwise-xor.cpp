class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n=derived.size();
        int pro=0;
        for(int i=0;i<n;i++){
            pro^=derived[i];
        }

        if(pro==0){
            return true;
        }

        return false;
    }
};