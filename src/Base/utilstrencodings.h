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


#endif // UTILSTRENCODINGS_H_H
