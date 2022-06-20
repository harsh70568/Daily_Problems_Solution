class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.length();
        int m = num2.length();
        
        string sum(n+m,'0');
        
        for(int i = n-1; i >= 0; i--)
        {
            int carry = 0;
            for(int j = m-1; j >= 0; j--)
            {
                int temp = carry + (num1[i]-'0')*(num2[j]-'0') + sum[i+j+1]-'0';
                sum[i+j+1] = (temp%10)+'0';
                carry = temp / 10;
            }
            sum[i] += carry;
        }
        
        int i = 0;
        while(i < sum.size() && sum[i] == '0') i++;
        if(i == sum.size()) return "0";
        else return sum.substr(i);
    }
};