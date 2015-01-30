# TaLibFuncView

![initial screen shot](https://github.com/jsoprych/TaLibFuncView/blob/master/doc/img/screenshot-20150129.png)

## What's so Funny about Peace, Love, and simple, statically linked, C++ cross-platform GUI's (where they still make sense -- like in financial trading applications )???

TaLibFuncView is a proof of concept, cross-platform, C++ 11 GUI that utilizes the FLTK (Fast Light Toolkit) window that displays meta-data for the functions found in the TA-Lib financial technical analysis package (over 150 functions).  


"In contrast to user interface libraries like GTK+, Qt, and wxWidgets, FLTK uses a more lightweight design and restricts itself to GUI functionality. Because of this, the library is very small (the FLTK "Hello World" program is around 100 KiB), and is usually statically linked. It also avoids complicated macros and separate code preprocessors, and does not use the following advanced C++ features: templates, exceptions, RTTI or, for FLTK 1.x, namespaces. Combined with the modest size of the package, this leads to a relatively short learning curve for new users."
(...from Wikipedia http://en.wikipedia.org/wiki/FLTK)

This project depends on FLTK and TA-Lib. More information on those dependencies can be found here:


FLTK: http://www.fltk.org/

TA-LIB: http://sourceforge.net/projects/ta-lib/
