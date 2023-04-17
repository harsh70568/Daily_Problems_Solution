class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        if(n == 2) return "11";
        
        string s = "11";
        for(int i = 3; i <= n; i++)
        {
            string t = "";
            int count = 1;
            s += '&';
            
            for(int j = 1; j < s.length(); j++)
            {
                if(s[j] == s[j-1])
                {
                    count++;
                }
                else
                {
                    t += to_string(count);
                    t += s[j-1];
                    count = 1;
                }
            }
            s = t;
        }
        
        return s;
    }
};