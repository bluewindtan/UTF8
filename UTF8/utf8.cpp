#include "utf8.h"


CUTF8::CUTF8()
{
}


CUTF8::~CUTF8()
{
}

int CUTF8::SplitWord2CharArray(const string & word, vector<string> & charArray)
{
    int num = word.size();
    int i = 0;
    int nCount = 0;
    while (i < num)
    {
        int size = 1;
        if (word[i] & 0x80)
        {
            char temp = word[i];
            temp <<= 1;
            do{
                temp <<= 1;
                ++size;
            } while (temp & 0x80);
        }
        string subWord = word.substr(i, size);
        charArray.push_back(subWord);
        nCount++;
        i += size;
    }

    return nCount;
}
