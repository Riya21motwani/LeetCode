class Solution {
public:
    int passThePillow(int n, int time) {
        int currentPillowPosition = 1;
        int currentTime = 0;
        int direction = 1;
        while (currentTime < time) {
            if (0 < currentPillowPosition + direction &&
                currentPillowPosition + direction <= n) {
                currentPillowPosition += direction;
                currentTime++;
            } else {
               
                direction *= -1;
            }
        }
        return currentPillowPosition;
    }
};