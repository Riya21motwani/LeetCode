/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        int h=n;
        while(l<=h){
            
            int mid=(l+(h-l)/2);
            
            int element= guess(mid);
            if(element==0){
                 return mid;
            }
            else if(element==-1){
                    h=mid-1;
            }
            else{
                  l=mid+1;
            }

        }
        return -1;
    }
};