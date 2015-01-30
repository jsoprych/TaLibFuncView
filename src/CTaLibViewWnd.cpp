#include "CTaLibViewWnd.h"

CTaLibViewWnd::CTaLibViewWnd()
{
  //ctor

}

CTaLibViewWnd::~CTaLibViewWnd()
{
  //dtor
}

void CTaLibViewWnd::show(){
  // SETUP Tree callback
  m_funcTree->callback(Tree_CB, this);


  loadTATreeView(m_funcTree);
  m_window->show();
}
