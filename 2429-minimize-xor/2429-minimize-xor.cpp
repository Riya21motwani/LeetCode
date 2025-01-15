class Solution {
public:

    bool isset(int &x, int pos){
        if((x&1<<pos)!=0){
            return true;
        }

        return false;
    }

    int set(int &x , int pos){

        return x=x|(1<<pos);
    }

    int unset(int &x , int pos){

        return x=x& ~(1<<pos);
    }


    int minimizeXor(int num1, int num2) {
        int x=num1;

        int n1=__builtin_popcount(num1);
        int n2=__builtin_popcount(num2);
        int pos=0;
        if(n1<n2){
            //set karna hai lsb ko

            while(n1<n2){
                if(!isset(x,pos)){
                    set(x,pos);
                    n1++;
                }
                pos++;
            }
        }else if(n1>n2){
            //unset krna hai lsb ko
            while(n1>n2){
                if(isset(x,pos)){
                    unset(x,pos);
                    n1--;
                }
                pos++;
            }

        }

        return x;
        
    }
};