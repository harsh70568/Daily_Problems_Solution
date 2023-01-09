class Solution {
public:
    
    int sieve(int N)
    {
        bool primes[N+1];
        memset(primes, true, sizeof(primes));
        
        primes[1] = false;
        for(int i = 2; i*i <= N; i++)
        {
            if(primes[i] == true)
            {
                for(int j = i*i; j <= N; j += i)
                {
                    primes[j] = false;
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i < N; i++)
        {
            if(primes[i] == true)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
    int countPrimes(int n) {
        if(n == 0) return 0;
        return sieve(n);
    }
};