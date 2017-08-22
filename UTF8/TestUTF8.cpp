// UTF8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <fstream>
#include <iterator>

#include "utf8.h"


std::map<std::string, unsigned int> m_mapDenies;

void TrimLeft(string &str, char c = ' ')
{
    if (str.empty())
        return;

    std::string::size_type nFirst = str.find_first_not_of(c);

    if (nFirst == std::string::npos)
        str.clear();
    else if (0 < nFirst && nFirst < str.size())
        str.erase(0, nFirst);
}

void TrimRight(string &str, char c = ' ')
{
    if (str.empty())
        return;

    std::string::size_type nLast = str.find_last_not_of(c);

    if (nLast == std::string::npos)
        str.clear();
    else
        str.erase(nLast + 1);
}

void TrimCR(string &str)
{
    while (str.size() > 0 &&
        (str[str.size() - 1] == '\r' || str[str.size() - 1] == '\n'))
    {
        str = str.substr(0, str.size() - 1);
    }
}

void MakeLower(std::string &rText)
{
    unsigned int i = 0;
    unsigned int nSize = rText.size();

    while (i < nSize)
    {
        if ((rText[i] & 0x80) == 0 && isalpha(rText[i]))
        {
            rText[i] = (char)tolower(rText[i]);
        }

        ++i;
    }
}

class FileLineData
{
public:
    FileLineData() {}
    ~FileLineData() {}

    operator const std::string& () const
    {
        return m_strData;
    }

    friend std::istream& operator >> (std::istream &stream, FileLineData &ref)
    {
        std::getline(stream, ref.m_strData);

        TrimCR(ref.m_strData);
        TrimLeft(ref.m_strData);
        TrimRight(ref.m_strData);

        return stream;
    }

private:
    std::string m_strData;
};

bool ReadInfoFromFile(const std::string &rFileName)
{
    if (rFileName.empty())
        return false;

    std::ifstream infile(rFileName.c_str());
    std::istream_iterator<FileLineData> input(infile);
    std::istream_iterator<FileLineData> eof;
    std::vector<std::string> denyText(input, eof);

    std::vector<std::string>::iterator itr;
    unsigned int nLength;

    for (itr = denyText.begin(); itr != denyText.end(); ++itr)
    {
        if (itr->empty())
        {
            continue;
        }

        MakeLower(*itr);

        nLength = (*itr).length();

        m_mapDenies.insert(std::make_pair(*itr, nLength));
    }

    return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

