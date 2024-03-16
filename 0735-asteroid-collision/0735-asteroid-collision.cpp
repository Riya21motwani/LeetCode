class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        vector<int>ans;
        stack<int>st;
        int sum=0;
      for(int & s:asteroids){
        while(!st.empty() && st.top()>0 && s<0){
            int sum=st.top()+s;
            if(sum<0){
                st.pop();
            }
            else if(sum>0){
                s=0;
                break;
            }
            else if(sum==0){
                st.pop();
                s=0;
                break;
            }
        }
        if(s!=0){
            st.push(s);
        }
      }

       int sos=st.size();
       int i=sos-1;
       vector<int>res(sos);
       while(!st.empty()){
           res[i]=st.top();
           st.pop();
           i--;
       }

    return res;
    }
};