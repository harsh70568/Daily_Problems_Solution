class Solution {
public:
    int sum(int num)
    {
        int s = 0;
        while(num)
        {
            s += (num % 10);
            num /= 10;
        }
        return s;
    }
    
    int addDigits(int num) {
        while(num > 9)
        {
            num = sum(num);
        }
        
        return num;
    }
};