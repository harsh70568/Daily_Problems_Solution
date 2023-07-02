class Solution {
public:
vector<int> sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i*i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    
    vector<int> arr;
    for(int i = 2; i <= n; i++) if(prime[i]) arr.push_back(i);
    
    return arr;
}
 
    vector<vector<int>> findPrimePairs(int n) {
        vector<int> arr = sieve(n);
        
        int i = 0;
        int j = arr.size()-1;
        
        vector<vector<int>> ans;
        while(i <= j)
        {
            if(arr[i] + arr[j] == n)
            {
                ans.push_back({arr[i], arr[j]});
                i++;
                j--;
            }
            else if(arr[i] + arr[j] < n) i++;
            else j--;
        }
        
        return ans;
    }
};