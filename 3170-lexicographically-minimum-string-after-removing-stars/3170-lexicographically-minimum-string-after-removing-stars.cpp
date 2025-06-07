class Solution {
public:

    typedef pair<int,int>p;
    struct comp{
        bool operator()(p &p1, p &p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };


    string clearStars(string s) {
        priority_queue<p,vector<p>,comp>pq;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }else{
                int idx=pq.top().second;
                s[idx]='*';
                pq.pop();
            }
        }
        string temp="";

        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                temp.push_back(s[i]);
            }
        }

        return temp;
    }
};