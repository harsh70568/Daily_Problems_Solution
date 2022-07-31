class Solution {
public:
    char solve(vector<int> count)
    {
            char ch;
            int maxi = INT_MIN;
        for(int i = 0; i < count.size(); i++)
        {
            if(count[i] > maxi)
            {
                maxi = count[i];
                ch = i+'a';
            }
        }
        return ch;
    }
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> count(26,0);
        for(int i = 0; i < s.length(); i++)
        {
            count[s[i] - 'a']++;
        }
        
        char max_ch = solve(count);
        int max_count = count[max_ch-'a'];
        if(max_count > (n+1)/2) return "";
        string str(n,' ');
        int index = 0;
        while(max_count--)
        {
            str[index] = max_ch;
            index = index+2;
        }
        count[max_ch-'a'] = 0;
        
        for(int i = 0; i < 26; i++)
        {
            while(count[i])
            {
                index = (index >= n) ? 1 : index;
                str[index] = i+'a';
                index = index+2;
                count[i]--;
            }
        }
        return str;
    }
};