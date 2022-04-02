class Solution {
public:
    int hammingDistance(int x, int y) {
        int different_bit = 0;
        int s =x^y;
        while(s){
            different_bit += s&1;
            s >>=1;
        }
        return different_bit;

    }
};