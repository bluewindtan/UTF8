#ifndef _UTF8_H_
#define _UTF8_H_

#include <string>
#include <vector>

using namespace std;

class CUTF8
{
private:
    CUTF8();
    ~CUTF8();
public:
    // 分解字符串中的每一个字符，存储到vector中
    static int SplitWord2CharArray(const string & word, vector<string> & characters);
};

#endif
