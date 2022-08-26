class Solution {
public:
    int bitwiseComplement(int n) {
        int count = 0;
        long long ans = 0;
        int num = n;
        for(int i = 0; i < 32; i++)
        {
            int k = (num >> i) & 1;
            if(k == 0)
            {
                ans += pow(2,count);
            }
            count++;
            n = n >> 1;
            if(n == 0) break;
        }
        return ans;
    }
};