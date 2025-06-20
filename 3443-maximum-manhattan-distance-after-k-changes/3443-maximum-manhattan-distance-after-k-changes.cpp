class Solution {
public:
    int maxDistance(string s, int k) {
        int n = 0, s_ = 0, e = 0, w = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (ch == 'N') n++;
            else if (ch == 'S') s_++;
            else if (ch == 'E') e++;
            else if (ch == 'W') w++;

            int k1 = k;

            int NS = abs(n - s_);
            int minNS = min(n, s_);
            int usedNS = min(minNS, k1);
            NS += usedNS * 2;
            k1 -= usedNS;

            int EW = abs(e - w);
            int minEW = min(e, w);
            int usedEW = min(minEW, k1);
            EW += usedEW * 2;
            k1 -= usedEW;

            ans = max(ans, NS + EW);
        }

        return ans;
    }
};