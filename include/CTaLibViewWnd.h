#ifndef CTALIBVIEWWND_H
#define CTALIBVIEWWND_H

#include "../fluidUI/CTaLibFuncViewUI.h"

class CTaLibViewWnd: public CTaLibFuncViewUI
{
  public:
    /** Default constructor */
    CTaLibViewWnd();
    /** Default destructor */
    virtual ~CTaLibViewWnd();
    void show();
  protected:
  private:
};

#endif // CTALIBVIEWWND_H
