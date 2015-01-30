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
