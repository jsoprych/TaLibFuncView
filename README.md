# TaLibFuncView (WARNING: Early stage Proof of Concept. Fluid API/Interface.)

![initial screen shot](https://github.com/jsoprych/TaLibFuncView/blob/master/doc/img/screenshot-dialog.png)

## What's so Funny about Peace, Love, and simple, statically linked, C++ cross-platform GUI's (where they still make sense -- like in financial trading applications )???

TaLibFuncView is a proof of concept, cross-platform, C++ 11 GUI that utilizes the FLTK (Fast Light Toolkit) in a custom modal dialog window that displays meta-data for all the functions found in the TA-Lib financial technical analysis package (over 150 functions).  

"In contrast to user interface libraries like GTK+, Qt, and wxWidgets, FLTK uses a more lightweight design and restricts itself to GUI functionality. Because of this, the library is very small (the FLTK "Hello World" program is around 100 KiB), and is usually statically linked. It also avoids complicated macros and separate code preprocessors..."
(...from Wikipedia http://en.wikipedia.org/wiki/FLTK)

In addition to over 150 technical analysis functions, TA-Lib also includes an optional abstract functional meta-data interface that can be accessed dynamically, as a shared library, that allows an application to query and execute newly added functions (either from future versions of TA-Lib, or propriatary user extensions) without modifying the original user interface code or even the binary executable.

TaLibFuncView is also designed to leverage the FLTK Fluid graplic interface designer which can output the necessary C++ code to implement a UI that is graphically composed.

![FLTK Fluid UI Designer](https://github.com/jsoprych/TaLibFuncView/blob/master/doc/img/fluid-gui.png)
         

This project depends on FLTK and TA-Lib libraries, and also assumes that both libraries are installed in their default locations, so you may need to make modifications where applicable if your configuration is customized. 

More information on the above dependencies (e.g. downloads, installation docs, licencing, etc) can be found here:

FLTK: http://www.fltk.org/

TA-LIB: http://sourceforge.net/projects/ta-lib/

Initial development on Linux (Ubuntu 14.04) using CodeBlocks IDE, but code should work on Windows and Mac with minor modifications. 

This project will probably also utilize SQLite (app meta data/configuration) and perhaps Redis (financial prices) in a later stage.
