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
    // �ֽ��ַ����е�ÿһ���ַ����洢��vector��
    static int SplitWord2CharArray(const string & word, vector<string> & characters);
};

#endif
