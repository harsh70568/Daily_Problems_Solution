class Solution {
public:
    int reverse(int x) {
        long long int y = 0;
        long long int range = pow(2,31);
        while(x)
        {
            int r = x % 10;
            y = y*10+r;
            x /= 10;
        }
        if(y < -range || y > range-1) return 0;
        else return y;
    }
};