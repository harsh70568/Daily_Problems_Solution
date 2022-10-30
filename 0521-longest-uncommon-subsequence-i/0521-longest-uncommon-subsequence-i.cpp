class Solution {
public:
    bool is_subseq(string &a, string &b)
    {
        int j = 0;
        for(int i = 0; i < b.length(); i++)
        {
            if(a[j] == b[i])
            {
                j++;
            }
        }
        
        return j == a.length();
    }
    int findLUSlength(string a, string b) {
        int maxi = INT_MIN;
        if(is_subseq(a, b) == false) maxi = a.length();
        
        if(is_subseq(b, a) == false)
        {
            int size = b.length();
            maxi = max(maxi, size);
        }
        return maxi == INT_MIN ? -1 : maxi;
    }
};