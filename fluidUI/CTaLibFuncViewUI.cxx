// generated by Fast Light User Interface Designer (fluid) version 1.0302

#include "CTaLibFuncViewUI.h"

CTaLibFuncViewUI::CTaLibFuncViewUI() {
  { m_window = new Fl_Double_Window(780, 385, "Technical Analysis Function Browser");
    m_window->user_data((void*)(this));
    { m_taLibView = new Fl_Group(-35, 0, 815, 470);
      m_taLibView->box(FL_DOWN_BOX);
      { Fl_Tile* o = new Fl_Tile(5, 5, 770, 345);
        o->box(FL_FLAT_BOX);
        o->color(FL_YELLOW);
        { m_funcTree = new Fl_Tree(5, 5, 260, 345);
          m_funcTree->color((Fl_Color)20);
          m_funcTree->root()->label("FUNCTIONS");
          m_funcTree->root()->labelcolor(FL_RED);
        } // Fl_Tree* m_funcTree
        { m_funcInfo = new Fl_Group(265, 5, 510, 345);
          m_funcInfo->box(FL_DOWN_BOX);
          m_funcInfo->color((Fl_Color)43);
          m_funcInfo->align(Fl_Align(65));
          { m_funcName = new Fl_Box(270, 10, 500, 25, "<-- Select a Function");
            m_funcName->labeltype(FL_SHADOW_LABEL);
            m_funcName->labelsize(20);
            m_funcName->labelcolor(FL_BACKGROUND2_COLOR);
            m_funcName->align(Fl_Align(FL_ALIGN_CLIP));
          } // Fl_Box* m_funcName
          { Fl_Tabs* o = new Fl_Tabs(270, 40, 505, 310);
            { m_summaryGroup = new Fl_Group(270, 60, 505, 290, "SUMMARY");
              { m_funcDescription = new Fl_Box(385, 68, 365, 55);
                m_funcDescription->labeltype(FL_SHADOW_LABEL);
                m_funcDescription->labelsize(20);
                m_funcDescription->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcDescription->align(Fl_Align(197|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcDescription
              { m_funcGroup = new Fl_Box(386, 125, 380, 25);
                m_funcGroup->labeltype(FL_SHADOW_LABEL);
                m_funcGroup->labelsize(20);
                m_funcGroup->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcGroup->align(Fl_Align(68|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcGroup
              { m_funcInputs = new Fl_Box(387, 157, 365, 30);
                m_funcInputs->labeltype(FL_SHADOW_LABEL);
                m_funcInputs->labelsize(20);
                m_funcInputs->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcInputs->align(Fl_Align(68|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcInputs
              { m_funcOptInputs = new Fl_Box(387, 195, 360, 30);
                m_funcOptInputs->labeltype(FL_SHADOW_LABEL);
                m_funcOptInputs->labelsize(20);
                m_funcOptInputs->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcOptInputs->align(Fl_Align(68|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcOptInputs
              { m_funcOutputs = new Fl_Box(387, 235, 325, 30);
                m_funcOutputs->labeltype(FL_SHADOW_LABEL);
                m_funcOutputs->labelsize(20);
                m_funcOutputs->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcOutputs->align(Fl_Align(68|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcOutputs
              { m_funcDisplayTypes = new Fl_Box(386, 278, 384, 69);
                m_funcDisplayTypes->labeltype(FL_SHADOW_LABEL);
                m_funcDisplayTypes->labelsize(20);
                m_funcDisplayTypes->labelcolor(FL_BACKGROUND2_COLOR);
                m_funcDisplayTypes->align(Fl_Align(69|FL_ALIGN_INSIDE));
              } // Fl_Box* m_funcDisplayTypes
              { Fl_Box* o = new Fl_Box(275, 70, 105, 25, " DESCRIPTION:");
                o->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
              } // Fl_Box* o
              { Fl_Box* o = new Fl_Box(275, 164, 105, 25, "         INPUTS:");
                o->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
              } // Fl_Box* o
              { new Fl_Box(279, 128, 105, 25, "         GROUP:");
              } // Fl_Box* o
              { Fl_Box* o = new Fl_Box(275, 200, 105, 25, "         OPT-INPUTS:");
                o->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
              } // Fl_Box* o
              { Fl_Box* o = new Fl_Box(275, 239, 105, 25, "         OUTPUTS:");
                o->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
              } // Fl_Box* o
              { Fl_Box* o = new Fl_Box(275, 280, 105, 25, "         VISUAL TYPE:");
                o->align(Fl_Align(FL_ALIGN_RIGHT|FL_ALIGN_INSIDE));
              } // Fl_Box* o
              m_summaryGroup->end();
            } // Fl_Group* m_summaryGroup
            { m_inputsTable = new Fl_Table(270, 60, 500, 280, "INPUTS");
              m_inputsTable->box(FL_THIN_UP_FRAME);
              m_inputsTable->hide();
              m_inputsTable->end();
            } // Fl_Table* m_inputsTable
            { m_optInputsTable = new Fl_Table(270, 60, 500, 280, "OPT-INPUTS");
              m_optInputsTable->box(FL_THIN_UP_FRAME);
              m_optInputsTable->hide();
              m_optInputsTable->end();
            } // Fl_Table* m_optInputsTable
            { m_outputsTable = new Fl_Table(270, 60, 500, 280, "OUTPUTS");
              m_outputsTable->box(FL_THIN_UP_FRAME);
              m_outputsTable->hide();
              m_outputsTable->end();
            } // Fl_Table* m_outputsTable
            o->end();
          } // Fl_Tabs* o
          m_funcInfo->end();
        } // Fl_Group* m_funcInfo
        o->end();
      } // Fl_Tile* o
      m_taLibView->end();
      Fl_Group::current()->resizable(m_taLibView);
    } // Fl_Group* m_taLibView
    m_window->end();
  } // Fl_Double_Window* m_window
}
