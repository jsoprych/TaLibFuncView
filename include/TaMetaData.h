#ifndef TAMETADATA_H
#define TAMETADATA_H

#include "util.h"

#include<ta-lib/ta_abstract.h>

class CTA_StringTable: public TA_StringTable{
  CTA_StringTable(){
    this->size = 0;
    this->string = nullptr;
  }

  ~CTA_StringTable(){
    if(this->size){


    }
  }


};

struct FuncInfo {
  std::string group;
  std::string name;
  TA_FuncInfo info;
};

typedef const char* CPStr;
typedef std::vector<CPStr> VCPStr;




enum class ParamMetaType {NUL = 0,INPUT,OUTPUT,OPT_INPUT};

/******************************************************************************

*******************************************************************************/

class ParamMeta {

  enum ParamMetaType _pmType;
  union{
    TA_InputParameterInfo    common;
    TA_InputParameterInfo    input;
    TA_OutputParameterInfo   output;
    TA_OptInputParameterInfo optInput;
  }_p;

public:
  ParamMeta(){
    // ZERO OUT STRUCTURE:
    clear();
  }

  ParamMeta(const TA_InputParameterInfo& input):ParamMeta(){
    *this = input;
  }

  ParamMeta(const TA_OptInputParameterInfo& optInput){
    *this = optInput;
  }

  ParamMeta(const TA_OutputParameterInfo& output){
    *this = output;
  }

  CPStr getType2Str(){
    switch(_pmType){
     case ParamMetaType::INPUT: return inputType2Str();
     case ParamMetaType::OPT_INPUT: return optInputType2Str();
     case ParamMetaType::OUTPUT: return outputType2Str();
    }
    return nullptr;
  }

  CPStr getFlags2Str(){
    switch(_pmType){
     case ParamMetaType::INPUT: return inputFlags2Str();
     case ParamMetaType::OPT_INPUT: return optInputFlags2Str();
     case ParamMetaType::OUTPUT: return outputFlags2Str();
    }
    return nullptr;
  }

  /********************************************
  typedef enum
  {
     TA_Input_Price,
     TA_Input_Real,
     TA_Input_Integer
  } TA_InputParameterType;
  *********************************************/
  CPStr inputType2Str(){
    std::string str;
    if(_pmType == ParamMetaType::INPUT){
      switch(_p.input.type){
        case TA_Input_Price:   return "Price";
        case TA_Input_Real:    return "Real";
        case TA_Input_Integer: return "Integer";
      }
    }
    return nullptr;
  }

  /********************************************

  *********************************************/
  CPStr optInputType2Str(){
    std::string str;
    if(_pmType == ParamMetaType::OPT_INPUT){
      switch(_p.optInput.type){
        case TA_Input_Price:   return "Price";
        case TA_Input_Real:    return "Real";
        case TA_Input_Integer: return "Integer";
      }
    }
    return nullptr;
  }

  /*********************************************
  typedef enum
  {
     TA_OptInput_RealRange,
     TA_OptInput_RealList,
     TA_OptInput_IntegerRange,
     TA_OptInput_IntegerList
  } TA_OptInputParameterType;

  **********************************************/
  CPStr outputType2Str(){
    std::string str;
    if(_pmType == ParamMetaType::OUTPUT){
      switch(_p.output.type){
        case TA_OptInput_RealRange:    return "RealRange";
        case TA_OptInput_RealList:     return "RealList";
        case TA_OptInput_IntegerRange: return "IntegerRange";
        case TA_OptInput_IntegerList:  return "IntegerList";
      }
    }
    return nullptr;
  }

  const char* getName(){return _p.common.paramName;}
  int getType(){return _p.common.type;}
  int getFlags(){return _p.common.flags;}

  /*******************************************
  #define TA_IN_PRICE_OPEN         0x00000001
  #define TA_IN_PRICE_HIGH         0x00000002
  #define TA_IN_PRICE_LOW          0x00000004
  #define TA_IN_PRICE_CLOSE        0x00000008
  #define TA_IN_PRICE_VOLUME       0x00000010
  #define TA_IN_PRICE_OPENINTEREST 0x00000020
  #define TA_IN_PRICE_TIMESTAMP    0x00000040
  ********************************************/
  CPStr inputFlags2Str(){
    VCPStr vCPStr;
    if(_pmType == ParamMetaType::INPUT){
      auto flags = _p.input.flags;
      if(flags & TA_IN_PRICE_OPEN)   vCPStr.push_back("OPEN");
      if(flags & TA_IN_PRICE_HIGH)   vCPStr.push_back("HIGH");
      if(flags & TA_IN_PRICE_LOW)    vCPStr.push_back("LOW");
      if(flags & TA_IN_PRICE_CLOSE)  vCPStr.push_back("CLOSE");
      if(flags & TA_IN_PRICE_VOLUME) vCPStr.push_back("VOLUME");
      if(flags & TA_IN_PRICE_OPENINTEREST) vCPStr.push_back("OPENINTEREST");
      if(flags & TA_IN_PRICE_TIMESTAMP) vCPStr.push_back("TIMESTAMP");
    }
    std::string s = "INPUT_FLAGS:" + UTL::implode(vCPStr, ",", "[", "]");

    return s.c_str();
  }


  /****************************************************
  typedef int TA_OptInputFlags;
  #define TA_OPTIN_IS_PERCENT   0x00100000  Input is a percentage.
  #define TA_OPTIN_IS_DEGREE    0x00200000  Input is a degree (0-360).
  #define TA_OPTIN_IS_CURRENCY  0x00400000  Input is a currency.
  #define TA_OPTIN_ADVANCED     0x01000000

  *****************************************************/
  CPStr optInputFlags2Str(){
    VCPStr vCPStr;
    if(_pmType == ParamMetaType::OPT_INPUT){
      auto flags = _p.optInput.flags;
      if(flags & TA_OPTIN_IS_PERCENT)  vCPStr.push_back("IS_PERCENT");
      if(flags & TA_OPTIN_IS_DEGREE)   vCPStr.push_back("IS_DEGREE");
      if(flags & TA_OPTIN_IS_CURRENCY) vCPStr.push_back("IS_CURRENCY");
      if(flags & TA_OPTIN_ADVANCED)    vCPStr.push_back("ADVANCED");
    }
    std::string s = "OPT_INPUT_FLAGS:" + UTL::implode(vCPStr, ",", "[", "]");

    return s.c_str();
  }

  /****************************************************
  typedef int TA_OutputFlags;
  #define TA_OUT_LINE              0x00000001  Suggest to display as a connected line.
  #define TA_OUT_DOT_LINE          0x00000002  Suggest to display as a 'dotted' line.
  #define TA_OUT_DASH_LINE         0x00000004  Suggest to display as a 'dashed' line.
  #define TA_OUT_DOT               0x00000008  Suggest to display with dots only.
  #define TA_OUT_HISTO             0x00000010  Suggest to display as an histogram.
  #define TA_OUT_PATTERN_BOOL      0x00000020  Indicates if pattern exists (!=0) or not (0)
  #define TA_OUT_PATTERN_BULL_BEAR 0x00000040  =0 no pattern, > 0 bullish, < 0 bearish
  #define TA_OUT_PATTERN_STRENGTH  0x00000080  =0 neutral, ]0..100] getting bullish, ]100..200] bullish, [-100..0[ getting bearish, [-200..100[ bearish
  #define TA_OUT_POSITIVE          0x00000100  Output can be positive
  #define TA_OUT_NEGATIVE          0x00000200  Output can be negative
  #define TA_OUT_ZERO              0x00000400  Output can be zero
  #define TA_OUT_UPPER_LIMIT       0x00000800  Indicates that the values represent an upper limit.
  #define TA_OUT_LOWER_LIMIT       0x00001000  Indicates that the values represent a lower limit.
  *****************************************************/
  CPStr outputFlags2Str(){
    VCPStr vCPStr;
    if(_pmType == ParamMetaType::OUTPUT){
      auto flags = _p.output.flags;
      if(flags & TA_OUT_LINE)              vCPStr.push_back("LINE");
      if(flags & TA_OUT_DOT_LINE)          vCPStr.push_back("DOT_LINE");
      if(flags & TA_OUT_DASH_LINE)         vCPStr.push_back("DASH_LINE");
      if(flags & TA_OUT_DOT)               vCPStr.push_back("DOT");
      if(flags & TA_OUT_HISTO)             vCPStr.push_back("HISTO");
      if(flags & TA_OUT_PATTERN_BOOL)      vCPStr.push_back("PATTERN_BOOL");
      if(flags & TA_OUT_PATTERN_BULL_BEAR) vCPStr.push_back("PATTERN_BULL_BEAR");
      if(flags & TA_OUT_PATTERN_STRENGTH)  vCPStr.push_back("PATTERN_STRENGTH");
      if(flags & TA_OUT_POSITIVE)          vCPStr.push_back("POSITIVE");
      if(flags & TA_OUT_NEGATIVE)          vCPStr.push_back("NEGATIVE");
      if(flags & TA_OUT_ZERO)              vCPStr.push_back("ZERO");
      if(flags & TA_OUT_UPPER_LIMIT)       vCPStr.push_back("UPPER_LIMIT");
      if(flags & TA_OUT_LOWER_LIMIT)       vCPStr.push_back("LOWER_LIMIT");
    }
    std::string s = "OUTPUT_FLAGS:" + UTL::implode(vCPStr, ",", "[", "]");

    return s.c_str();
  }

  ParamMeta& operator = (const TA_InputParameterInfo& input){
    clear();
    _pmType = ParamMetaType::INPUT;
    _p.input = input;
    return *this;
  }

  ParamMeta& operator = (const TA_OptInputParameterInfo& optInput){
    clear();
    _pmType = ParamMetaType::OPT_INPUT;
    _p.optInput = optInput;
    return *this;
  }

  ParamMeta& operator = (const TA_OutputParameterInfo& output){
    clear();
    _pmType = ParamMetaType::OUTPUT;
    _p.output = output;
    return *this;
  }

private:
  void clear(){ memset(this,0,sizeof(ParamMeta));}

};


/******************************************************************************

******************************************************************************/

struct FuncMeta: public TA_FuncInfo{
  public:
  std::vector<ParamMeta> _paramInfo;

  FuncMeta(){}

  FuncMeta(TA_FuncInfo taFI){
    *this = taFI;
  }

  int loadParamInfo(){
    _paramInfo.clear();
    loadInputInfo();
    loadOptInputInfo();
    loadOutputInfo();
    return _paramInfo.size();

  }

  FuncMeta& operator = (const TA_FuncInfo& taFI){
    this->camelCaseName = taFI.camelCaseName;
    this->flags         = taFI.flags;
    this->group         = taFI.group;
    this->handle        = taFI.handle;
    this->hint          = taFI.hint;
    this->name          = taFI.name;
    this->nbInput       = taFI.nbInput;
    this->nbOptInput    = taFI.nbOptInput;
    this->nbOutput      = taFI.nbOutput;

    return *this;
  }

  protected:

  int loadInputInfo(){
    unsigned int count = 0;
    const TA_InputParameterInfo *inputPI;
    //_paramInfo.clear();
    for(int i=0; i < this->nbInput; i++ ){
      TA_RetCode retCode = TA_GetInputParameterInfo( this->handle, i, &inputPI);
      if(retCode == TA_SUCCESS ){
        ParamMeta pm(*inputPI);
        _paramInfo.push_back(pm);
        count ++;
      }
    }
    return count;
  }

  int loadOptInputInfo(){
    unsigned int count = 0;
    const TA_OptInputParameterInfo *optInputPI;
    //_paramInfo.clear();
    for(int i=0; i < this->nbInput; i++ ){
      TA_RetCode retCode = TA_GetOptInputParameterInfo( this->handle, i, &optInputPI);
      if(retCode == TA_SUCCESS ){
        ParamMeta pm(*optInputPI);
        _paramInfo.push_back(pm);
        count ++;
      }
    }
    return count;
  }

  int loadOutputInfo(){
    unsigned count = 0;
    const TA_OutputParameterInfo *outputPI;
    //_paramInfo.clear();
    for(int i=0; i < this->nbInput; i++ ){
      TA_RetCode retCode = TA_GetOutputParameterInfo( this->handle, i, &outputPI);
      if(retCode == TA_SUCCESS ){
        ParamMeta pm(*outputPI);
        _paramInfo.push_back(pm);
        count ++;
      }
    }
    return count;
  }



};

typedef std::vector<FuncInfo> VFuncInfo;

class TaMetaData
{
  public:
    /** Default constructor */
    TaMetaData() {}
    /** Default destructor */
    virtual ~TaMetaData() {}

    int getTAGroups(std::vector<std::string>& vStr){
      TA_StringTable *table;
      TA_RetCode retCode;

      retCode = TA_GroupTableAlloc( &table );

      if( retCode == TA_SUCCESS ){
        int len = table->size;
        vStr.clear();
        for(int i=0; i < len; i++ ){
          std::string g =  table->string[i];
          //g += "/A";
          vStr.push_back(g);
        }
        TA_GroupTableFree(table);
        return len; // LENGTH OF RETURNED GROUP ITEMS
      }
      return -1; // ERROR
    }


    TA_FuncInfo getFuncInfo(const char*funcName){
      TA_RetCode retCode;
      const TA_FuncHandle *handle;
      const TA_FuncInfo *theInfo = nullptr;
      TA_FuncInfo fInfo = {};

      retCode = TA_GetFuncHandle(funcName, &handle );

      if( retCode == TA_SUCCESS ){
        retCode = TA_GetFuncInfo( handle, &theInfo );
        if( retCode == TA_SUCCESS){
          std::cout << "GOT FUNC INFO FOR " << funcName << std::endl;
          return *theInfo;
        }
        else{
          std::cout << "ERROR GETTiNG FUNC INFO FOR " << funcName << "Error:" << retCode << std::endl;
        }
      }
      return fInfo;
    }



    int getFuncInfosByGroup(const char* group, VFuncInfo& vFInfo){
      TA_StringTable *table;
      TA_RetCode retCode;

      retCode = TA_FuncTableAlloc(group, &table);

      if( retCode == TA_SUCCESS ){
        int len = table->size;
        vFInfo.clear();
        for(int i=0; i < len; i++ ){
          FuncInfo fi;

          fi.group = group;
          fi.name  = table->string[i];
          fi.info  = getFuncInfo(fi.name.c_str());

          {
            FuncMeta ma(fi.info);
            int x = ma.loadParamInfo();
            std::cout << "FuncMeta: " << ma.group << ": " << ma.name << ": InputParams:" << x << std::endl;
            for(auto s: ma._paramInfo){
              std::cout << "  name = " << s.getName() << ": type = " << s.getType2Str() <<  ": " << s.getFlags2Str() << std::endl;
            }
          }

          vFInfo.push_back(fi);

        }
        TA_FuncTableFree(table);
        return len; // LENGTH OF RETURNED GROUP ITEMS
      }
      return -1; // ERROR
    }

  protected:



    void displayInputType( const TA_FuncInfo *funcInfo ){
      unsigned int i;
      const TA_InputParameterInfo *paramInfo;

      for( i=0; i < funcInfo->nbInput; i++ ){

        TA_GetInputParameterInfo( funcInfo->handle, i, &paramInfo );
        switch( paramInfo->type ){
          case TA_Input_Price:
            printf( "This function needs price bars as input\n" );
            break;
          case TA_Input_Real:
            printf( "This function needs an array of floats as input\n" );
            break;
          case TA_Input_Integer:
            printf( "This function needs an array of floats as input\n" );
            break;
          default:
            break;
            //(... etc. ...)
         }
      }
    }

  private:
};


typedef std::vector<FuncMeta> VFuncMeta;
class TaLibMetaData {
  VCPStr    _vGroup;
  VFuncMeta _vFuncMeta;
  public:
  TaLibMetaData(){

  }
  virtual ~TaLibMetaData(){}

  const FuncMeta& operator [](int idx){
    return _vFuncMeta[idx];
  }


  int loadFuncGroups(){
    TA_StringTable *table;

    _vGroup.clear();
    if(TA_SUCCESS == TA_GroupTableAlloc( &table )){
      int len = table->size;
      for(int i=0; i < len; i++ ){
        _vGroup.push_back(table->string[i]);
      }
      TA_GroupTableFree(table);
    }
    return _vGroup.size();
  }


  static void createFuncMetas( const TA_FuncInfo *funcInfo, void *voidThis){
    auto pMD = (TaLibMetaData *)voidThis;

    FuncMeta fm(*funcInfo);
    fm.loadParamInfo();
    pMD->_vFuncMeta.push_back(fm);
  }

  bool loadFuncInfo(){
    _vFuncMeta.clear(); // clear previous vector
    return (TA_SUCCESS == TA_ForEachFunc(createFuncMetas, this));
  }

  const VFuncMeta getFuncsByGroup(CPStr group = nullptr){
    VFuncMeta vFm;
    if(group == nullptr){
      for(auto fm: _vFuncMeta)vFm.push_back(fm);
    }
    else{
      for(auto fm: _vFuncMeta){
        if(strcmp(group, fm.group) == 0){
          vFm.push_back(fm);
        }
      }
    }
    return vFm;
  }



  int loadFuncInfoByGroup(CPStr group = nullptr){
    TA_StringTable *table;
    const TA_FuncHandle  *handle;
    const TA_FuncInfo    *funcInfo;

    _vGroup.clear();
    // Get list of function names for group. If group null, get ALL function names.
    if(TA_SUCCESS == TA_FuncTableAlloc(group, &table )){
      int len = table->size;
      // For each function name ...
      for(int i=0; i < len; i++ ){
        CPStr funcName = table->string[i];
        // ... get TA-lib handle for function name...
        if(TA_SUCCESS == TA_GetFuncHandle(funcName, &handle)){
          // With handle, get function info structure used to make a FuncMeta object.
          if(TA_SUCCESS == TA_GetFuncInfo(handle, &funcInfo)){
            FuncMeta fm(*funcInfo);
            fm.loadParamInfo();
            // Add fully initialized FuncMeta object to a list.
            _vFuncMeta.push_back(fm);
          }
        }
      }
      // Free table memory
      TA_FuncTableFree(table);
    }
    // return number of FuncMeta objects on list
    return _vFuncMeta.size();
  }

  VTreeItem getTreeList(){
    VTreeItem vTreeList;
    loadFuncInfoByGroup(); // load all functions
    int len = _vFuncMeta.size();
    for(int i = 0; i < len; i++){
      std::stringstream ss[2];
      const FuncMeta fm = _vFuncMeta[i];

      int id = i + 1; // IMPORTANT: adding 1 to ZERO based index. Remember to subtract when accessing!!!

      ss[0] << "Order By Group" << '/' << "ALL Groups" << '/' << fm.name << "(" << fm.camelCaseName << ")" ;

      vTreeList.push_back(TreeItem{ss[0].str(), id}); // ADDING 1 to zero based index, so 0 is null


      ss[1] << "Order By Group" << '/' << fm.group << '/' << fm.name << "(" << fm.camelCaseName << ")" ;
       vTreeList.push_back(TreeItem{ss[1].str(), id});
    }
    return vTreeList;
  }
};

#endif // TAMETADATA_H
