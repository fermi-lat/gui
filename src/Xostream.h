//   $Header: /cvsroot/d0cvs/gui/motif/Xostream.h,v 1.1 1999/11/03 04:36:56 burnett Exp $
// Project:
//  author: Toby Burnett
//
//  Declare text output window for Motif environment, with
//  possibility of clear and label of window

#ifndef XOSTREAM_H
#define XOSTREAM_H
 

#include "gui/GUI.h"


class Xostream : public std::ostream
{
public:
    Xostream(const char* name);
    void clear();
    void flush();
private:
};


#endif

