// $Header: /cvsroot/d0cvs/gui/windows/WinGUIostream.h,v 1.1 1999/11/03 04:38:56 burnett Exp $
#include "WinGUI.h"

#ifndef WINGUIOSTEAM_H
#define WINGUIOSTEAM_H

#define USECONSOLE  // rather than create a window, that doesn't work now

class logbuf;
#include <iostream>
using namespace std;

class WinGUIostream : public ostream
{
public:
    WinGUIostream(const char* name, HWND parent, HINSTANCE hInst);
    
    ~WinGUIostream();
    
    void clear();
private:
    logbuf* _buf;
#ifndef USECONSOLE
    HWND _win;  // the dialogbox window
#endif
};


#endif
