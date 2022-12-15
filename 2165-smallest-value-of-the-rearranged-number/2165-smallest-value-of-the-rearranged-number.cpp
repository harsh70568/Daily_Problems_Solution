class Solution {
public:
    long long smallestNumber(long long num) {
        int sign = num > 0 ? 1 : -1;
        
        string str = to_string(num);
        int cnt = 0;
        string pos = "";
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == '0') cnt++;
            else pos += str[i];
        }
        
        
        if(sign == 1)
        {
            sort(pos.begin(), pos.end());
            string ans = "";
            ans += pos[0];
            while(cnt--)
            {
                ans += '0';
            }
            for(int i = 1; i < pos.size(); i++)
            {
                ans += pos[i];
            }
            cout<<ans;
            num = stol(ans);
        }
        else
        {
            sort(str.begin(), str.end());
            reverse(str.begin(), str.end());
            num = stol(str);
            num = -1*num;
        }
        
        return num;
    }
};