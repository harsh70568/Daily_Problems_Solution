class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int n = num1.length();
        int m = num2.length();
        int i = 0;
        int j = 0;
        int fd = 0;
        int sd = 0;
        int carry = 0;
        while(i < n || j < m)
        {
            if(i < n)
            {
                fd = num1[i]-'0';
            }
            else
            {
                fd = 0;
            }
            if(j < m)
            {
                sd = num2[i]-'0';
            }
            else
            {
                sd = 0;
            }
            int sum = carry + fd + sd;
            ans.append(to_string(sum % 10));
            carry = sum / 10;
            i++;
            j++;
        }
        if(carry == 1)
        {
            ans.append(to_string(1));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};