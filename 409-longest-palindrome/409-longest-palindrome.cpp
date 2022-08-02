class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mpp;
        int sum = 0;
        for(int i = 0; i < s.length(); i++)
        {
            mpp[s[i]]++;
        }
        bool is_first_odd = false;
        for(auto it : mpp)
        {
            if(it.second % 2 == 0)
            {
                sum += it.second;
            }
            else
            {
                if(is_first_odd == false)
                {
                    sum += it.second;
                    is_first_odd = true;
                }
                else
                {
                    sum += it.second-1;
                }
            }
        }
        return sum;
    }
};