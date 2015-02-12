/*
    Copyright (c) 2015, John Soprych
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef const char* C_Str;
typedef string Str;
typedef vector<Str> VStr;
typedef vector<C_Str> VC_Str;

template<class T>
struct CStrDataPair{
  Str str;
  T data;
};

// Tree string data (index) pair
typedef CStrDataPair<int> TreeItem;

// Vector of TreeItmes used to build tree
typedef vector<TreeItem> VTreeItem;


class UTL
{
  public:
    /** Default constructor */
    UTL() {}
    /** Default destructor */
    virtual ~UTL() {}

    static Str implode(VC_Str& vC_Str, const char* delim = "|", const char* lEnd = "", const char* rEnd = ""){
      Str s;

      s += lEnd;
      int len = vC_Str.size();
      for(int x=0; x<len; x++){
        if(x) s += delim;
          s += vC_Str[x];
        }
      s += rEnd;

    return s;
    }

  protected:
  private:
};

#endif // UTIL_H
