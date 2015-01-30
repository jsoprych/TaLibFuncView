#ifndef CTALIBVIEWWND_H
#define CTALIBVIEWWND_H

#include "../fluidUI/CTaLibFuncViewUI.h"

#include "TaMetaData.h"

#include <stdio.h>

class CTaLibViewWnd: public CTaLibFuncViewUI
{
  TaLibMetaData _TaMD; // Used to access Technical Analysis function meta data
  public:
    /** Default constructor */
    CTaLibViewWnd();
    /** Default destructor */
    virtual ~CTaLibViewWnd();
    void show();
  protected:

    /**
    load tree view with TA-lib function info
    */

    void loadTATreeView(Fl_Tree* pTree){
      //TaLibMetaData TaMD;

      _TaMD.loadFuncInfo();

      VTreeItem vList = _TaMD.getTreeList();

      pTree->clear();
      for(auto ti: vList){
          Fl_Tree_Item *i = pTree->add(ti.str.c_str());
          // TODO: MAY WANT TO IMPROVE CASTING OF VOID* TO LONG VALUE
          i->user_data((void*)(ti.data)); // <-- ASSIGN index TO this group
          auto v = (long)i->user_data();
      }
      pTree->root()->labelcolor(FL_RED);
      pTree->root()->label("FUNCTIONS");
      pTree->root()->user_data((void*)-1);
      pTree->redraw();
    }

  private:

    static void Tree_CB(Fl_Widget *w, void *data) {

      CTaLibViewWnd *wnd = (CTaLibViewWnd*)data;
     Fl_Tree *tree = (Fl_Tree*)w;
     Fl_Tree_Item *item = (Fl_Tree_Item*)tree->callback_item();
     if ( ! item ) return;
     switch ( tree->callback_reason() ) {
       case FL_TREE_REASON_SELECTED: {
         char pathname[256];
         tree->item_pathname(pathname, sizeof(pathname), item);
         if ( Fl::event_button() == FL_RIGHT_MOUSE )
             { fprintf(stderr, "** RIGHT MOUSE **: "); }
         long v = (long)item->user_data();
         fprintf(stderr, "Tree_CB: Item selected='%s', Full pathname='%s' and index = %ld\n", item->label(), pathname, v);

         if(v>0){ // IFWE HAVE A VALID ID
           const FuncMeta& fm = wnd->_TaMD[(v-1)];
           cout << "HINT:" << fm.hint << endl;
           wnd->m_funcName->label(fm.name);
           wnd->m_funcDescription->label(fm.hint);
           wnd->m_funcInfo->activate();
         }
         else{
          wnd->m_funcName->label("<-- Select a Function");
          wnd->m_funcInfo->deactivate();
         }
         break;
       }
       case FL_TREE_REASON_DESELECTED:
         fprintf(stderr, "Tree_CB: Item '%s' deselected\n", item->label());
         break;
       case FL_TREE_REASON_OPENED:
         fprintf(stderr, "Tree_CB: Item '%s' opened\n", item->label());
         break;
       case FL_TREE_REASON_CLOSED:
         fprintf(stderr, "Tree_CB: Item '%s' closed\n", item->label());
       default:
         break;
     }
 }
};

#endif // CTALIBVIEWWND_H
