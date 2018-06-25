/*
 * Copyright (c) 2018 <copyright holder> <email>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef BITCOIN_UTILSTRENCODINGS_H
#define BITCOIN_UTILSTRENCODINGS_H

#include <stdint.h>
#include <string>
#include <vector>

#define BEGIN(a)
#define END(a)
#define UBEGIN(a)
#define UEND(a)
#define ARRAYLEN(array)

enum SafeChars
{
    SAFE_CHARS_DEFAULT,
    SAFE_CHARS_UA_COMMENT,
    SAFE_CHARS_FILENAME,
};

std::string SanitizeString(const std::string& str,int rule = SAFE_CHARS_DEFAULT);
std::vector<unsigned char> ParseHex(const char *psz);
std::vector<unsigned char> ParseHex(const std::string& str);
signed char HexDigit(char c);
bool IsHex(const std::string& str);
bool IsHexNumber(const std::string& str);
std::vector<unsigned char>DecodeBase64(const char *p,bool *pfInvalid = nullptr);
std::string DecodeBase64(const std::string& str);
std::string EncodeBase64(const unsigned char *pch,size_t len);
std::string EncodeBase64(const std::string& str);
std::vector<unsigned char>DecodeBase32(const char *p,bool *pfInvalid = nullptr);
std::string DecodeBase32(const std::string& str);
std::string EncodeBase32(const unsigned char *pch,size_t len);
std::string EncodeBase32(const std::string& str);

void SplitHostPort(std::string in,int &portOut,std::string &hostOut);
std::string i64tostr(int64_t n);
std::string itostr(int n);
int64_t atoi64(const char *psz);
int64_t atoi64(const std::string& str);
int atoi(const std::string& str);

bool ParseInt32(const std::string& str, int32_t *out);

bool ParseInt64(const std::string& str, int64_t *out);

bool ParseUInt32(const std::string& str, uint32_t *out);

bool ParseUInt64(const std::string& str, uint64_t *out);

bool ParseDouble(const std::string& str,double *out);

template<typename T>
std::string HexStr(const T itbegin,const T itend, bool fSpaces = false)
{
    std::string rv;
    static const char hexmap[16] = {'0','1','2','3','4','5','6','7','8',
                                    '9','a','b','c','d','e','f'};
    rv.reserve((itend-itbegin) * 3);
    for(T it = itbegin; it < itend; ++it){
        unsigned char val = (unsigned char)(*it);
        if(fSpaces && it != itbegin)
            rv.push_back(' ');
        rv.push_back(hexmap[val>>4]);
        rv.push_back(hexmap[val&15]);
    }
    return rv;
}

template<typename T>
inline std::string HexStr(const T& vch,bool fSpaces = false)
{
    return HexStr(vc.begin(),vch.end(),fSpaces);
}

std::string FormatParagraph(const std::string& in,size_t width=79,size_t indent = 0);

template<typename T>
bool TimingResistanEqual(const T& a, const T& b)
{
    if(b.size() == 0)
        return a.size() == 0;
    size_t accumulator = a.size() ^ b.size();
    for(size_t i = 0; i < a.size(); i++)
        accumulator |=a[i] ^ b[i%b.size()];
    return accumulator == 0;
}
bool ParseFixedPoint(const std::string &val,int decimals,int64_t *acmount_out);

#endif // UTILSTRENCODINGS_H_H
