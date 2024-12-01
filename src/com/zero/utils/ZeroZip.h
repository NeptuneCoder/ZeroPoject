#pragma once
using namespace std;
#include <string>
#include <vector>

class ZeroZip
{
private:
    /* data */
    int decompressData(const std::vector<unsigned char> &input, std::vector<unsigned char> &output);
    int compressData(const std::string &input, std::vector<unsigned char> &output);

public:
    ZeroZip(/* args */);
    void test();
    ~ZeroZip();
};
