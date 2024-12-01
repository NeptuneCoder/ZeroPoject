#include <iostream>
#include "ZeroZip.h"
#include <zlib.h>
ZeroZip::ZeroZip(/* args */)
{
}

// 压缩数据
int ZeroZip::compressData(const std::string &input, std::vector<unsigned char> &output)
{
    uLong sourceLen = input.size();
    uLong destLen = compressBound(sourceLen);

    output.resize(destLen); // 分配足够的空间

    int result = compress(output.data(), &destLen, reinterpret_cast<const unsigned char *>(input.c_str()), sourceLen);
    if (result != Z_OK)
    {
        std::cerr << "Compression failed with error code: " << result << std::endl;
        return result;
    }

    output.resize(destLen); // 压缩后的数据大小可能小于初始分配的空间
    return Z_OK;
}

// 解压数据
int ZeroZip::decompressData(const std::vector<unsigned char> &input, std::vector<unsigned char> &output)
{
    uLong sourceLen = input.size();
    uLong destLen = sourceLen * 4; // 初步分配一个合理大小的缓冲区

    output.resize(destLen); // 分配足够的空间

    // 使用 reinterpret_cast 进行转换
    int result = uncompress(output.data(), &destLen,
                            input.data(), sourceLen);
    if (result != Z_OK)
    {
        std::cerr << "Decompression failed with error code: " << result << std::endl;
        return result;
    }

    output.resize(destLen); // 解压后的数据大小可能小于初始分配的空间
    return Z_OK;
}

void ZeroZip::test()
{
    std::string originalText = "This is a test string that will be compressed using zlib.";
    std::vector<unsigned char> compressedData;

    // 压缩数据
    if (compressData(originalText, compressedData) == Z_OK)
    {
        std::cout << "Compression succeeded. Compressed size: " << compressedData.size() << " bytes." << std::endl;
    }

    std::vector<unsigned char> decompressedData;
    // 解压数据
    if (decompressData(compressedData, decompressedData) == Z_OK)
    {
        std::string decompressedText(decompressedData.begin(), decompressedData.end());
        std::cout << "Decompression succeeded. Decompressed string: " << decompressedText << std::endl;
    }
}
ZeroZip::~ZeroZip()
{
    std::cout << "zeroZip destructor" << std::endl;
}
