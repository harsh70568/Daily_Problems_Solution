class Solution {
public:
    void solve(string num, int index, bool &flag)
    {
        if(index >= num.length())
        {
            if(num[0] != '0'){
            int num1 = stoi(num);
            if((num1 & num1-1) == 0) flag = true;
            }
            return;
        }
        
        for(int i = index; i < num.length(); i++)
        {
            swap(num[index],num[i]);
            solve(num,index+1,flag);
            swap(num[index],num[i]);
        }
    }
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        
        int index = 0;
        bool flag = false;
        solve(num,index,flag);
        return flag;
    }
};