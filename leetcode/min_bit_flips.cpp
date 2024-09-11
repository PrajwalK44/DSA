class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res=0;

        int n=start ^ goal;

        while(n){
            res+=n & 1;
            n >>=1;
        }
        return res;
    }
};