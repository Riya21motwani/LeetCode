class Solution {
public:
    
    typedef pair<char,int>p;
    
    struct comparator{
              bool operator()( p&p1,p&p2){
                     if(p1.first==p2.first){
                          return p1.second < p2.second;
                     }
                  return p1.first>p2.first;
              }
    
    };
    
    string clearStars(string s) {
        int n=s.size();  
        priority_queue<p,vector<p>,comparator>pq;
        
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
                
           }else{
                  int ind=pq.top().second;
                   pq.pop();
                s[ind]='*';
             } 
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
            ans.push_back(s[i]);
        }
    }
        return ans;
    }
};