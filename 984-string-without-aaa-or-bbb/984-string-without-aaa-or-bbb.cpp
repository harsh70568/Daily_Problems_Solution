class Solution {
public:
    string strWithout3a3b(int a, int b) {
        int count_a = 0;
        int count_b = 0;
        string ans = "";
        
        while(a > 0 && b > 0)
        {
            if(a >= b && count_a < 2)
            {
                ans += 'a';
                count_a += 1;
                count_b = 0;
                a--;
            }
            else if(count_b < 2)
            {
                ans += 'b';
                count_a = 0;
                count_b += 1;
                b--;
                
            }
            else{
                ans += 'a';
                count_a += 1;
                count_b = 0;
                a--;
            }
            
            // if(b >= a && count_b < 2)
            // {
            //     ans += 'b';
            //     count_b += 1;
            //     b--;
            // }
            // else
            // {
            //     ans += 'a';
            //     count_b = 0;
            //     count_a += 1;
            //     a--;
            // }
        }
        
        while(a--)
        {
            ans += 'a';
        }
        
        while(b--)
        {
            ans += 'b';
        }
        
        return ans;
    }
};