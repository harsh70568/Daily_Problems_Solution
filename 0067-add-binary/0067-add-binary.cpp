class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
        {
            string temp = a;
            a = b;
            b = temp;
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
       
        string ans = "";
        int val = 0;
        int carry = 0;
        int i = 0;
        int j = 0;
        while(i < a.length() || j < b.length())
        {
            val = (a[i] - '0') + carry;
            if(j < b.length()) val += (b[i] - '0');
            
            if(val == 3)
            {
                ans += to_string(1);
                carry = 1;
            }
            else if(val == 2)
            {
                ans += to_string(0);
                carry = 1;
            }
            else if(val == 1)
            {
                ans += to_string(1);
                carry = 0;
            }
            else
            {
                ans += to_string(0);
                carry = 0;
            }
            i++;
            if(j < b.length()) j++;
        }
        if(carry == 1)
        {
            ans += to_string(1);
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};