class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        int cnt = 0;
        int n = s.length(), m = goal.length();
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i]) cnt++;
        }
        
        if(cnt == 0)
        {
            set<char> s1(s.begin(), s.end());
            return !(s1.size() == s.size());
        }
        else if(cnt == 2){
        char c1, c2;
        bool flag = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != goal[i] && flag == false)
            {
                c1 = s[i];
                c2 = goal[i];
                flag = true;
            }
            else if(s[i] != goal[i] && flag)
            {
                if(s[i] != c2 || goal[i] != c1) return false;
            }
        }
            return true;
        }
        else return false;
    }
};