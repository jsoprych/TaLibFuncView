# TaLibFuncView (WARNING: Early stage Proof of Concept. Fluid API/Interface.)

![initial screen shot](https://github.com/jsoprych/TaLibFuncView/blob/master/doc/img/screenshot-20150129.png)

## What's so Funny about Peace, Love, and simple, statically linked, C++ cross-platform GUI's (where they still make sense -- like in financial trading applications )???

TaLibFuncView is a proof of concept, cross-platform, C++ 11 GUI that utilizes the FLTK (Fast Light Toolkit) in custom window that displays all meta-data for the functions found in the TA-Lib financial technical analysis package (over 150 functions).  


"In contrast to user interface libraries like GTK+, Qt, and wxWidgets, FLTK uses a more lightweight design and restricts itself to GUI functionality. Because of this, the library is very small (the FLTK "Hello World" program is around 100 KiB), and is usually statically linked. It also avoids complicated macros and separate code preprocessors..."
(...from Wikipedia http://en.wikipedia.org/wiki/FLTK)

In addition to over 150 technical analysis functions, TA-Lib also includes an optional abstract functional meta-data interface that can be accessed dynamically, as a shared library, that allows an application to query and execute newly added functions (either from later versions of TA-Lib, or propriatary user extensions) without modifying the original user interface code or even the binary executable. 
         

This project depends on FLTK and TA-Lib. More information on those dependencies can be found here:


FLTK: http://www.fltk.org/

TA-LIB: http://sourceforge.net/projects/ta-lib/

Initial development on Linux (Ubuntu 14.04) using CodeBlocks IDE, but code should work on Windows and Mac with minor modifications. 

This project will probably also utilize SQLite (app meta data/configuration) and perhaps Redis (financial prices) in a later stage.
