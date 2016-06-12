/*********************************************************************************************
思路：如果该数字在数组中只有一个，那么将所有数字异或后剩下的数字即为该数字，基于这个思路，将所
有的数字进行异或后得到了两个不同的数字的异或结果，结果中存在1的位数即为两个数字不同的位数，以该位
是否为1为标准，将数组分成两组，然后在每一组中分别找出对应的出现一次的数字。
**********************************************************************************************/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) 
    {
		int length = data.size();
  		if(length < 2)
        {
            *num1 = 0;
            *num2 = 0;
            return;
        }
        int temp = 0;
        for(int i = 0;i < length;++i)
        {
            temp ^= data[i];
        }
        int index = FindFirstBit1(temp);
        *num1 = *num2 = 0;
        for(int i = 0; i < length; ++i)
        {
            if(IsBit1(data[i],index))
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }
    }
private:
    int FindFirstBit1(int num)
    {
        int index = 0;
        while((num&1)==0&&index < 32)
        {
            index++;
            num = num >> 1;
                
        }
        return index;
    }
    bool IsBit1(int num, int index)
    {
        if((num >> index) & 1)
            return true;
        return false;
    }
};
