class Solution {
public:
    int multiply(int A, int B) {
        if(A > B){
            swap(A, B);
        }
        int ans = 0;
        if( A > 0){
            int a = A;
            int tmp = -1;
            while(a > 0){
                a = a >> 1;
                tmp++;
            }
            if(tmp > 0){
                ans += B << tmp;
                cout << ans <<endl;
                
                cout << A - (1 << tmp) << " " <<  B <<endl;
                ans += multiply(A - (1 << tmp), B);
                cout << ans <<endl;
            }else{
                ans = B;
            }
        }
        return ans;
    }
};