class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0, res = 0;
        while (m != n)
        {
            m >>= 1;
            n >>= 1;
            count ++;
        }
        res = n<<count;

        return res;
    }
};