#ifndef __GUIFIELD_H__
#define __GUIFIELD_H__

#include <FL/FL.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

class GUIField : Fl_Window {
public:
    GUIField();
    ~GUIField();
    void changeColor(int field_index, int color_index);
    void setColor(int* index);
    void random();
private:
    Fl_Button *pa[400];
};

#endif
