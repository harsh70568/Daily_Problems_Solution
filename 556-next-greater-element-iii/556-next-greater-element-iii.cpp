class Solution {
public:
    int nextGreaterElement(int num) {
        string str = to_string(num);
        
        int n = str.length();
        int i,j;
        for(i = n-2; i >= 0; i--)
        {
            if(str[i+1] > str[i]) break;
        }
        
        if(i < 0) return -1;
        
        for(j = n-1; j > i; j--)
        {
            if(str[j] > str[i]) break;
        }
        swap(str[i],str[j]);
        reverse(str.begin()+i+1,str.end());
        
        return stol(str) > INT_MAX ? -1 : stol(str);
    }
};