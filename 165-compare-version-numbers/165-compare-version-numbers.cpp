class Solution {
public:
    int compareVersion(string v1, string v2) {
        int num1 = 0;
        int num2 = 0;
        for(int i = 0,j = 0; (i < v1.length() || j < v2.length());)
        {
            while(i < v1.length() && v1[i] != '.')
            {
                num1 = num1*10+(v1[i]-'0');
                i++;
            }
            
            while(j < v2.length() && v2[j] != '.')
            {
                num2 = num2*10+(v2[j]-'0');
                j++;
            }
            
            if(num1 > num2) return 1;
            else if(num1 < num2) return -1;
            else
            {
                num1 = 0;
                num2 = 0;
            }
            i++;
            j++;
        }
        return 0;
    }
};