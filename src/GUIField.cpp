#include "GUIField.hpp"
#include <unistd.h>

GUIField::GUIField() : Fl_Window(400, 400, "GUI") {
    for (int i = 0; i < 400; i++) {
        Fl_Button *b = new Fl_Button(20*(i/20), 20*(i%20), 20, 20, "");
        b->color(FL_WHITE);
        pa[i] = b;
    }
    show();
}

GUIField::~GUIField() {
}

void GUIField::changeColor(int field_index, int color_index) {
    switch(color_index) {
    case 0:
        pa[field_index]->color(FL_WHITE);
        break;
    case 1:
        pa[field_index]->color(FL_BLACK);
        break;
    case 2:
        pa[field_index]->color(FL_GREEN);
        break;
    case 3:
        pa[field_index]->color(FL_RED);
        break;
    case 4:
        pa[field_index]->color(FL_BLUE);
        break;
    case 5:
        pa[field_index]->color(FL_GRAY);
        break;
    default:
        printf("error!\nAt GUIField::changeColor\n");
        exit(1);
    }
    Fl::check();
    redraw();
}

void GUIField::setColor(int* index) {
    for (int i = 0; i < 400; i++) {
        switch(index[i]) {
        case 0:
            pa[i]->color(FL_WHITE);
            break;
        case 1:
            pa[i]->color(FL_BLACK);
            break;
        case 2:
            pa[i]->color(FL_GREEN);
            break;
        case 3:
            pa[i]->color(FL_RED);
            break;
        case 4:
            pa[i]->color(FL_BLUE);
            break;
        case 5:
            pa[i]->color(FL_GRAY);
            break;
        default:
            printf("error!\nAt GUIField::changeColor\n");
            exit(1);
        }
    }
    Fl::check();
    redraw();
}

void GUIField::random() {
    for(int i = 0; i < 100; i++) {
        usleep(1000);
        int rnd = rand() % 400;
        changeColor(rnd, 1);
    }
}
