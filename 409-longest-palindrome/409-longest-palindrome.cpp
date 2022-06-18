class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        int sum = 0;
        bool odd = false;
        for(auto it : mpp)
        {
            if(it.second % 2 == 0)
            {
                sum += it.second;
            }
            else
            {
                sum += it.second-1;
                odd = true;
            }
        }
        if(odd) return sum+1;
        else return sum;
    }
};