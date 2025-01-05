class Solution {
public:
    bool hasMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        int pos=-1;
        
        for(int i=0;i<m;i++){
            if(p[i]=='*'){
                pos=i;
                break;
            }
        }


        if(pos==0){
            string p1=p.substr(1);
            if(p1.size()>s.size()){
                return false;
            }
            for(int i=0;i<=n-(p1.size());i++){
                string temp=s.substr(i,p1.size());
                if(temp==p1){
                    return true;
                }
            }
            return false;
        }
        else if(pos==m-1){
            string p1=p.substr(0,m-1);
            if(p1.size()>n){
                return false;
            }

            for(int i=0;i<=n-p1.size();i++){
                string temp=s.substr(i,p1.size());
                if(temp==p1){
                    return true;
                }
            }
            return false;
        }

        //* in between


        else{
            string p1=p.substr(0,pos);
            string p2=p.substr(pos+1);
            if(p1.size()+p2.size()>n){
                return false;
            }

            for(int i=0;i<=(n-p1.size()-p2.size());i++){
                string temp1=s.substr(i,p1.size());
                if(temp1==p1){
                    for(int t=i+p1.size();t<=n-p2.size();t++){
                        string temp2=s.substr(t,p2.size());
                        if(temp2==p2){
                            return true;
                        }
                    }
                }

                
            }
            return false;
        }
return false;






    }
};