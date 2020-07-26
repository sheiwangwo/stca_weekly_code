class Solution {
public:
    int maximum(int a, int b) {
        uint64_t dif = (uint64_t)a - (uint64_t)b;
        int k = dif >> 63; // 符号位
        // return (1 + k) * a - b * k;
        return a*(k^1) + b*k;
    }
};