class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        for(int i = 0; i < n; i++)
        {
            if(haystack[i] == needle[0])
            {
                int j = i;
                int z = 0;
                while(j < n && haystack[j] == needle[z])
                {
                    j++;
                    z++;
                }
                if(z == m) return i;
            }
        }
        return -1;
    }
};