class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t multiplier = 1 << 31, res = 0;
        while (n) res += multiplier * (n & 1), n >>= 1, multiplier >>= 1;
        return res;
    }
};
